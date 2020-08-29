/*
Aggressive Cows Problem

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows. 
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Sample Input :
1
5 3
1
2
8
4
9
Sample Output:
3 
Output details:
FJ can put his 3 cows in the stalls at positions 1, 4 and 8, 
resulting in a minimum distance of 3.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool checker(vector<ll> v,ll distance,ll cows,ll n){
    ll save = v[0];
        for(int i=1;i<n;i++){
            if(v[i]-save >= distance){
                cows--;
                save = v[i];
            }
            if(cows==0) return true;
        }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,c;
        cin>>n>>c;
        vector<ll> v(n);
        for(ll i=0;i<n;i++) cin>>v[i];
        sort(v.begin(),v.end());
        ll lb=0,ub=v[n-1]-v[0];
        ll d=0;ll saver=0;
        while(lb<=ub){
               //cout<<lb<<" "<<ub<<" ";
            d = (lb+ub)/2;//cout<<d<<" ";
            bool f=checker(v,d,c-1,n);
            if(f) {lb=d+1;saver=d;}//cout<<"true\n";}
            else {ub=d-1;}//cout<<"false\n";}
         
        }
        cout<<saver<<endl;
    }
}