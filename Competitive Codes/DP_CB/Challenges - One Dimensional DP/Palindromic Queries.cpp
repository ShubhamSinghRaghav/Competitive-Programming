/*

Given a string s and m queries . Each query consists of (l,r) where 1 <= l <= r <= n(size of string).

You need to print whether l to r is a palindromic string or not.

A string can be called palindrome if its reverse is same as itself . Ex - "aba" .

Input Format
First line contains n Second lines contains a string of length n. Next line contains m where m is the number of queries . Next m lines contains two integers l,r as described in the question.

Constraints
n <= 1000

m <= 100000

Output Format
for every query from l to r print "YES" if s[l…..r] is palindrome else print "NO" without quotes in a new line.

Sample Input
5
abbac
2
1 4
2 4
Sample Output
YES
NO
Explanation
s[1….4]="abba", it is a palindrome.

*/
#include<bits/stdc++.h>
using namespace std;
//top down approach
int solve(int dp[][1001],int l,int r,string s){
	if(l>=r)return 1;
	if(dp[l][r]>-1) return dp[l][r];
	dp[l][r] = solve(dp,l+1,r-1,s) and s[l]==s[r];
	//cout<<l+1<<" "<<r+1<<" "<<dp[l][r]<<"\n";
	return dp[l][r];
}
int main () {
    int n;
	cin>>n;
	string s;
	cin>>s;
	int t; cin>>t;
	int dp[1001][1001];
	for(int i=0;i<n+1;i++) for(int j=0;j<n+1;j++) dp[i][j] = -1;
	while(t--){
		int x,y;
		cin>>x>>y;
		if(solve(dp,x-1,y-1,s))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}