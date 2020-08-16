//minimum coins to reach sum;
#include <bits/stdc++.h>
using namespace std;
#define ll long long
//top down approach
int minimum(vector<int>& coin,int total,int dp[],int n){
    if(n==0) return 0;
    if(dp[n]!=0)return dp[n];
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        if(total - coin[i] > 0){
            int subp = minimum(coin,total - coin[i],dp,n);
            ans = min(subp+1,ans);
        }
    }
    dp[total] = ans;
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> coin(n);
    for(int i=0;i<n;i++) cin>>coin[i];
    int total;
    cin>>total;
    //bottom up approach
    int dp[1000];
    dp[0] = 0;
    for(int i=1;i<=total;i++){
        dp[i] = INT_MAX;
        for(int j=0;j<n;j++){
            if(i-coin[j]>=0){
                int subp = dp[i-coin[j]];
                dp[i] = min(subp+1,dp[i]);
            }
        }
    }
    cout<<dp[total];
    return 0;
}
