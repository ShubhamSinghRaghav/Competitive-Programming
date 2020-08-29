/*
Roy and Coin Boxes

Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.
Input
First line contains N - number of coin boxes.
Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.a
Output
For each query output the result in a new line.
Constraints
1 ≤ N ≤ 1000000

1 ≤ M ≤ 1000000

1 ≤ L ≤ R ≤ N

1 ≤ Q ≤ 1000000

1 ≤ X ≤ N
Sample Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long
#define MAX 1000007
ll start[MAX];
ll ender[MAX];
ll dp[MAX];
ll hashe[MAX];
int main(){
    ll n;
    cin>>n;
    //for(ll i=0;i<MAX;i++) 
    for(ll i=0;i<MAX;i++) {start[i]=0;ender[i]=0;dp[i]=0;hashe[i]=0;}
    ll m;
    cin>>m;
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        start[x]++;
        ender[y]++;
    }
    
   // dp[0]=start[1];
    //hashe[dp[0]]++;
    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1] + start[i] - ender[i-1];
        hashe[dp[i]]++;
    }
    for(ll i=MAX-3;i>=1;i--){
        hashe[i] += hashe[i+1];
    }
    ll q;cin>>q;
    while(q--){
        ll ans;cin>>ans;
        cout<<hashe[ans]<<endl;
    }
    return 0;
}
