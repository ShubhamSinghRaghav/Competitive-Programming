/*

Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.

Input Format
First line contains an integer t denoting the number of test cases. Next t lines contain an integer n each.

Constraints
1<= n < 30

Output Format
Output t lines each line describing the answer.

Sample Input
1
3
Sample Output
4
Explanation
{1}, {2}, {3} : all single {1}, {2,3} : 2 and 3 paired but 1 is single. {1,2}, {3} : 1 and 2 are paired but 3 is single. {1,3}, {2} : 1 and 3 are paired but 2 is single. Note that {1,2} and {2,1} are considered same.

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//top down approach
ll solve(int n,ll dp[]){
	if(n==0) return 1;
	if(dp[n]!=0) return dp[n];
	ll op1=0,op2=0;
	op1 = solve(n-1,dp);
	op2 = (n-1)*solve(n-2,dp);
	dp[n] = op1 + op2;
	return dp[n];
} 
int main() {
	ll dp[31]={0};
	solve(30,dp);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<dp[n]<<"\n";
	}
	return 0;
}