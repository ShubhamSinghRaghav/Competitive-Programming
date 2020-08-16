/*

Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, In how many ways can we make the change? The order of coins doesn’t matter.

Input Format
First line of input contain two space separated integers N and M. Second line of input contains M space separated integers - value of coins.

Constraints
1<=N<=250 1<=m<=50 1 <= Si <= 50

Output Format
Output a single integer denoting the number of ways to make the given change using given coin denominations.

Sample Input
10 4
2 5 3 6
Sample Output
5

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
//top down approach
ll solve(ll dp[][51],vector<int>& v,int i,int sum,int n){
	if(sum==0) {return 1;}
	if(sum<0 or i==n) return 0;
	if(dp[sum][i]>-1)return dp[sum][i];
	ll op1=0,op2=0;
	op1 = solve(dp,v,i,sum-v[i],n);
	op2 = solve(dp,v,i+1,sum,n);
	dp[sum][i] = op1 + op2;
	return dp[sum][i];
}

int main() {
	//count=0;
	int sum,n;
	cin>>sum>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	ll dp[251][51]={0};
	for(int i=0;i<251;i++){
		for(int j=0;j<51;j++){
			dp[i][j]=-1;
		}
	}
	cout<<solve(dp,v,0,sum,n);
	return 0;
}