/*
Alternatively selects coins such that sum becomes max.
Players selects at the begining or at the end only.
*/

#include <bits/stdc++.h>
using namespace std;
#define N 5000
#define ll long long
#define INF 100000000099ll
ll dp[N][N];
int solve(int i,vector<int>& coins,int j){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll op1 = coins[i] + min(solve(i+2,coins,j),solve(i+1,coins,j-1));//min bcz P2 takes max so P1 has min option left
    ll op2 = coins[j] + min(solve(i+1,coins,j-1),solve(i,coins,j-2));
    dp[i][j] = max(op1,op2);//bcz P1 has to take max to win
    return dp[i][j];
}

int main() {
	int n;
	cin>>n;
	vector<int> coins(n);
	for(int i=0;i<n;i++)cin>>coins[i];
	for(int i=0;i<N;i++)
	    for(int j=0;j<N;j++)
	        dp[i][j]=-1;
	cout<<solve(0,coins,n-1);
	return 0;
}
