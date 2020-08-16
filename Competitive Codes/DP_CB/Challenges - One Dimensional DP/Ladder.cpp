//Ladders Problem 
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
//top down approach
ll Ladders(int n,int k,ll dp[]){
    if(n==0) return 1ll;
    ll op=0;
    for(int i=1;i<=k;i++){
        if(n-i>=0){
            op += Ladders(n-i,k,dp);
        }
    }
    dp[n] = op;
    return dp[n];
}

int main(){
    //total steps
    int n;
    cin>>n;
    //atmost k steps 
    int k;
    cin>>k;
    //bottom up approach
    //sliding window of k size sum
    ll dp[1001]={0};
    dp[1]=1;
    dp[0]=1;
    for(int i=2;i<=k;i++) dp[i] = 2*dp[i-1];
    for(int i=k+1;i<=n;i++) dp[i] = 2*dp[i-1] + dp[i-k-1];
    cout<<dp[n]<<"\n";
    //cout<<Ladders(n,k,dp)<<"\n";
}