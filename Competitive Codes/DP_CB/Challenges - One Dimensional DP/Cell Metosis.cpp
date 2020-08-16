//Cell_metosis
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
//top down approach
ll Cell_metosis(int n,ll dp[],int x,int y,int z){
    if(n<=1) return 0;
    if(dp[n]>-1) return dp[n];
    int op1,op2;
    op1 = op2 = INT_MAX;
    if(n%2==0){
        op1 = x + Cell_metosis(n/2,dp,x,y,z);
        op2 = y + Cell_metosis(n-1,dp,x,y,z);
        dp[n] = min(op1,op2);
    }else{
        op1 = y + Cell_metosis(n-1,dp,x,y,z);
        op2 = x + z + Cell_metosis((n+1)/2,dp,x,y,z);
        dp[n] = min(op1,op2);
    }
    return dp[n];
}

int main(){
    //total cells to reach from 1 cell
    int n;
    cin>>n;
    //x,y,z costs for 2*cell ; cell + 1 ; cell -1; 
    int x,y,z;
    cin>>x>>y>>z;
    //bottom up approach
    //sliding window of k size sum
    ll dp[1001]={0};
    for(int i=0;i<1001;i++) dp[i] = -1;
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=n;i++){
        if(i%2==0){
            dp[i] = min(dp[i/2]+x,dp[i-1]+y);
        }else{
            dp[i] = min(dp[(i+1)/2]+x+z,dp[i-1]+y);
        }
    }
    cout<<dp[n];
    cout<<Cell_metosis(n,dp,x,y,z)<<"\n";
}