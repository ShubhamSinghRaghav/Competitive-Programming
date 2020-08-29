/*
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

Output
Output one integer, the maximum number of activities that can be performed
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long
struct act{
    ll s;
    ll f;
};
bool check(act x,act y){
    if(x.f < y.f ) return true;
    return false;
}
int main(){
    ll n;
    cin>>n;
    act v[n];
    for(int i=0;i<n;i++){
        cin>>v[i].s>>v[i].f;
    }
    sort(v,v+n,check);
    // for(int i=0;i<n;i++){
    //     cout<<v[i].a<<" "<<v[i].b<<"\n";
    // }
    ll c=1;
    act save = v[0];
    for(int i=1;i<n;i++){
        if(save.f <= v[i].s){
           c++;
           save = v[i];
        }else{
            if(v[i].f<=save.f) save = v[i];
        }
    }
    cout<<c;
    return 0;
}