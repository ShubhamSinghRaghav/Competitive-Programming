/*
You want to paint your house. The total area of your house is D units. There are a total of N workers. The ith worker is available after time Ti, has hiring cost Xi and speed Yi. This means he becomes available for hiring from time Ti and remains available after that. Once available, you can hire him with cost Xi, after which he will start painting the house immediately, covering exactly Yi units of house with paint per time unit. You may or may not hire a worker and can also hire or fire him at any later point of time. However, no more than 1 worker can be painting the house at a given time.
Since you want the work to be done as fast as possible, figure out a way to hire the workers, such that your house gets painted at the earliest possible time, with minimum cost to spend for hiring workers.
Note: You can hire a previously hired worker without paying him again.
Input
The first line of input contains two integers "N D", the number of workers and the area of your house respectively. The ith of the next N lines denotes the ith worker, and contains three integers "Ti Xi Yi", described in the statement.
Output
Output one integer, the minimum cost that you can spend in order to get your house painted at the earliest.
Constraints
1 ≤ N, T, X, Y ≤ 10^5
1 ≤ D ≤ 10^11
Sample Input
3 3
1 1 1
2 2 2
3 1 5
Sample Output
3
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct paint{
  ll t; ll x; ll y;
};
bool check(paint a,paint b){
    if(a.t==b.t){
        if(a.y==b.y){
            return (a.x < b.x);
        }
        return (a.y > b.y);
    }
    return (a.t < b.t);
}
int main(){
    ll n;
    cin>>n;
    ll d;
    cin>>d;
    paint v[n];
    for(int i=0;i<n;i++){
        cin>>v[i].t>>v[i].x>>v[i].y;
    }
    sort(v,v+n,check);
    ll done_ar = 0;
    ll t_cost = v[0].x;
    ll curr_i = 0;
    
    for(ll i=1;i<n  and done_ar<d;i++){
        ll time_g = v[i].t - v[i-1].t;
        done_ar += time_g*(v[curr_i].y);
        if(done_ar>=d) break;
        if(v[curr_i].y < v[i].y){
            curr_i = i;
            t_cost += v[curr_i].x;
        }
    }
    cout<<t_cost;
    return 0;
}









