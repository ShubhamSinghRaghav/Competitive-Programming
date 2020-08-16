/*

Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Input Format
n, size of array Ai, value of array elements

Constraints
1<= n <= 10^5 1<= Ai <=10^5

Output Format
Maximum value obtainable by cutting up the rod and selling the pieces.

Sample Input
5
1 2 3 4 5
Sample Output
5

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100002
ll solve(vector<int>& v,int n,vector<ll>& dp){
	if(n<=0) return 0;
	if(dp[n]!=-1) return dp[n];
	ll ans=0;
	for(int i=0;i<n;i++){
		ans = max(ans,v[i] + solve(v,n-i-1,dp));
	}
	dp[n] = ans;
	return dp[n];
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	vector<ll> dp(MAX);
	for(int i=0;i<=n;i++) dp[i] = -1;
	cout<<solve(v,n,dp);
	return 0;
}