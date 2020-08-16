/*

Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m . A tile can either be placed horizontally or vertically.

Input Format
First line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains two integers N and M.

Constraints
1 <= T<= 1000
1 <= N,M <= 100000

Output Format
Print answer for every test case in a new line modulo 10^9+7.

Sample Input
2
2 3
4 4
Sample Output
1
2

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
//top down approach
int solve(int n,int m,ll dp[100001]){
	if(m>n) return 1;
	if(dp[n]!=0)return dp[n];
	ll op1,op2;
    op1 = solve(n-1,m,dp);
	op2 = solve(n-m,m,dp);
	dp[n] = (op1 + op2)%mod;
	return dp[n];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		if(m>n){cout<<1<<"\n";continue;}
		else{
		    //bottom up approach
			ll dp[n+1];
			for(int i=m;i<=n;i++){
				//long a1,a2;
				if(i-1<m) dp[i-1] = 1;
				if(i-m<m) dp[i-m] = 1;
				dp[i] = (dp[i-1] + dp[i-m])%mod;
			}
			cout<<dp[n]<<"\n";
		}
	}
	return 0;
}