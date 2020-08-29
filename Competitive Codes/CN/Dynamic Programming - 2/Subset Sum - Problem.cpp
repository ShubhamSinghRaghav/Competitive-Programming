/*
Subset Sum - Problem
Send Feedback
Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.
Input Format
First line contains a single integer n (1<=n<=1000)
Second line contains n space separated integers (1<=a[i]<=1000)
Last line contains a single positive integer k (1<=k<=1000)
Output Format
Output Yes if there exists a subset whose sum is k, else output No.
Sample Input
3
1 2 3
4
Sample Output
Yes
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> val(n);
    for(int i=0;i<n;i++) cin>>val[i];
    int sum;
    cin>>sum;
    bool dp[n+1][sum+1];
    dp[0][0]=true;
    for(int i=1;i<=sum;i++) dp[0][i] = false;
    for(int i=1;i<=n;i++) dp[i][0] = true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=val[i-1])
            dp[i][j] = dp[i][j] or dp[i-1][j-val[i-1]];
        }
    }
    cout<<(dp[n][sum]?"Yes":"No");
    return 0;
}
