/*
Distinct Subsequences

Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters.
For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.
Input
First line of input contains an integer T which is equal to the number of test cases. You are required to process all test cases. Each of next T lines contains a string s.
Output
Output consists of T lines. Ith line in the output corresponds to the number of distinct subsequences of ith input string. Since, this number could be very large, you need to output ans%1000000007 where ans is the number of distinct subsequences. 
Constraints and Limits
T ≤ 100, length(S) ≤ 100000

All input strings shall contain only uppercase letters.
Sample Input
3
AAA
ABCDEFG
CODECRAFT
Sample Output
4
128
496
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long 
#define mod 1000000007
ll subs(string s){
    int n = s.size();
    vector<int> dp(n+1);
    vector<int> freq(26,-1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i] = (2*dp[i-1])%mod;
        if(freq[s[i-1]-'A']!=-1)
            dp[i] = (dp[i] - dp[freq[s[i-1]-'A']]+mod)%mod;
        freq[s[i-1]-'A'] = i-1; 
    }
    return dp[n];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<subs(s)<<"\n";
    }
    return 0;
}
