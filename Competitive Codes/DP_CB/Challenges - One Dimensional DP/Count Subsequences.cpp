/*

Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters. For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.

Input Format
First line of input contains an integer 't' denoting number of test cases.
Next t lines contain a string each.

Constraints
1<=t<=100
1<=length of s<=100000
s will contain upper letters only.

Output Format
For each test case ,print ans%1000000007 in a new line each ,where ans is the number of distinct subsequences.

Sample Input
2
AAA
ABCDEFG
Sample Output
4
128
Explanation
For "AAA" , the distinct subsequences that can be formed are { '', 'A' , 'AA' , 'AAA }. So we print 4 , no of distinct subsequences.
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int solve(){
	string s;
	cin>>s;
	int n = s.size();
	ll dp[n+1];
	dp[0]=1;
	vector<int> freq(26,-1);
	for(int i=1;i<=n;i++){
		dp[i] = (2*dp[i-1])%mod;
		if(freq[s[i-1]-'A']!=-1){
			dp[i] = (dp[i] - dp[freq[s[i-1]-'A']]+mod)%mod;
		}
		freq[s[i-1]-'A'] = i-1;
	}
	return dp[n];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cout<<solve();
		cout<<"\n";
	}
	return 0;
}