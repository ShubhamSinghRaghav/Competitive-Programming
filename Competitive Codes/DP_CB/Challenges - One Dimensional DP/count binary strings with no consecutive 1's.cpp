/*

You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

Input Format
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.

Constraints
1<=t<=100 1<=n<=90

Output Format
Print the number of all possible binary strings.

Sample Input
2
2
3
Sample Output
3
5
Explanation
1st test case : 00, 01, 10 2nd test case : 000, 001, 010, 100, 101

*/
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define mod 1000000007
//top down approach 
ll solve(int n,ll dp[][2],int val){
	if(n==0) return 1;
	if(dp[n][val]!=0)return dp[n][val];
	ll op1=0,op2=0;
	op1 = solve(n-1,dp,0);
	if(val==0) op2 = solve(n-1,dp,1);
	dp[n][val] = (op1 + op2);
	return dp[n][val];
}
//bottom up approach
ll solve1(){
    ll fb[91];
	fb[1]=2;
	fb[2]=3;
	for(int i=3;i<91;i++){
		fb[i] = fb[i-1]+fb[i-2];
	}
}
int main() {
	ll dp[101][2]={0};
	solve(100,dp,0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<dp[n][val]<<"\n";
	}
	return 0;
}