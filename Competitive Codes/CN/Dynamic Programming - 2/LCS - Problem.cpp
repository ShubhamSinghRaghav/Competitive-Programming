/*
LCS - Problem

Given 2 strings of S1 and S2 with lengths m and n respectively, find the length of longest common subsequence.
A subsequence of a string S whose length is n, is a string containing characters in same relative order as they are present in S, but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to n. For example, subsequences of string "abc" are - "",a,b,c,ab,bc,ac,abc.
Input Format :
Line 1 : String S1
Line 2 : String s2
Output Format :
Line 1 : Length of longest common subsequence
Sample Input :
adebc
dcadb
Sample Output :
3
*/

#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

int lcs(string a, string b){
    int m = a.size();
    int n = b.size();
    vector< vector<int>> dp(m+1, vector<int>(n+1,0));
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 or j==0) {dp[i][j] = 0;continue;}
            if(a[i-1]==b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}


int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2);
}