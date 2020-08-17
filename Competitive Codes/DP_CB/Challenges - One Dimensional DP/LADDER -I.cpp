/*

Let's define a new game of snakes and ladders. There is only one dimension of n cells. Each cell either contains a snake or ladder. 
One can simply take a jump of not more than k cells. A person cannot step on a snake. However, s/he can jump over a snake.
Alice is excited to play this game and is asking you to calculate the number of ways to finish the game.
Game starts at 1st cell and ends at the nth cell. It is guaranteed that there is a ladder at the 1st cell.
Since the number can be large, output the answer modulo (109+7).

Input Format
First line contains 2 integers N and K, denoting the number of cells and the maximum possible jump respectively. 
The next line contains N integers, x1, x2,…., xN, where xi is either 0 or 1. 
xi=0 denotes that there is a ladder in ith cell, xi=1 denotes that there is a snake in ith cell.

Constraints
1<=N<=10^4 1<=K<=10^4 0<=xi<=1

Output Format
Output a single integer denoting the number of ways to finish the game modulo (109+7).

Sample Input
5 2
0 0 0 1 0
Sample Output
2

Explanation
There are 2 ways to reach the 5th cell - [1,2,3,5] and [1,3,5].

*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MAX 10001
#define ll long long
ll solve(vector<int>& v,int i,int n,ll dp[MAX],int k){
    if(i>=n) return 0ll;
    if(i==n-1) return 1ll;
    if(dp[i]>0) return dp[i];
    if(v[i]==1){
        //dp[i] = 0ll;
        return 0ll;
    }else{
        ll ans=0;
        for(int j=1;j<=k;j++){
            if(i+j<n and v[i+j]==0){
                ans = (ans + solve(v,i+j,n,dp,k))%mod;
            }
        }
        dp[i]=ans;
       return dp[i];
    }
}
int main (){
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	ll dp[MAX];
	for(int i=0;i<=n;i++){
	    dp[i] = -1;
	    //dp[i][1] = -1;
	}
	cout<<solve(v,0,n,dp,k);
	return 0;
}
