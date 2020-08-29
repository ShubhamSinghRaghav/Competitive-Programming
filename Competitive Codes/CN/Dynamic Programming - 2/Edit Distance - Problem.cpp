/*
Edit Distance - Problem

Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
Line 1 : Edit Distance value
Constraints
1<= m,n <= 20
Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/

#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

int editDistance(string a, string b){
    int m = a.size();
    int n = b.size();
    vector< vector<int> > dp(m+1, vector<int>(n+1,0));
    for(int i=1;i<=m;i++)     dp[i][0] = i;
    for(int i=1;i<=n;i++)     dp[0][i] = i;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = min(1+dp[i-1][j-1],min(1+dp[i-1][j],1+dp[i][j-1]));
            }
        }
    }
    return dp[m][n];
}

int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}