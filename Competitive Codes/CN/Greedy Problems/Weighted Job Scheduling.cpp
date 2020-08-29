/*
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long
struct job{
    ll s,f,p;
};
bool check(job a,job b){
    if(a.f < b.f) return true;
    return false;
}

int main(){
    ll n;
    cin>>n;
    job v[n+1];
    vector<ll> fin(n+1);
    for(ll i=0;i<n;i++){
        cin>>v[i].s>>v[i].f>>v[i].p;
        fin[i] = v[i].f;
    }fin[n]=0;
    v[n].s=v[n].f=v[n].p=0;
    sort(v,v+n+1,check);
    sort(fin.begin(),fin.end());
    auto it = fin.begin();
    ll dp[n];
    dp[0]=0;
    dp[1] = v[1].p;
    if(v[2].s >= v[1].f) dp[2] = dp[1] + v[2].p;
    else dp[2] = max(v[2].p,dp[1]);
    for(ll i=3;i<=n;i++){
        if(v[i].s >= v[i-1].f){
            dp[i] = dp[i-1] + v[i-1].p;
        }else{
            ll ind = upper_bound(fin.begin(),fin.begin()+i+1,v[i].s)-it;
            ind--;
            dp[i] = max(dp[i-1],dp[ind]+v[i].p);
        }
    }
    cout<<dp[n];
    return 0;
}