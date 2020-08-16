//minimum Steps to 1;either n/3 or n/2 or n-1;
#include <bits/stdc++.h>
using namespace std;
#define ll long long
//top down approach
int recurse(int n,int dp[]){
    if(n==1)return 0;
    if(dp[n]!=0){
        return dp[n];
    }
    int op1,op2,op3,
    op1 = op2 = op3 = INT_MAX;
    if(n%2==0) op1 = recurse(n/2,dp);
    if(n%3==0) op2 = recurse(n/3,dp);
    op3 = recurse(n-1,dp);
    dp[n] = min(op1,min(op2,op3)) + 1;
    return dp[n];
}

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    //bottom up approach
    int dp[100000];
    dp[0] = 0;
    dp[1] = 0;
    for(int i=1;i<=n;i++){
        int op1=op2=op3=INT_MAX;
        if(n%2==0) op1 = dp[i/2];
        if(n%3==0) op2 = dp[i/3];
        op3 = dp[i-1];
        dp[i] = min(op1,min(op2,op3)) + 1;
    }
    cout<<dp[n];
    return 0;
}