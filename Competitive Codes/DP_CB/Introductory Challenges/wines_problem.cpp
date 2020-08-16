//wines problem;
#include <bits/stdc++.h>
using namespace std;
#define ll long long
//top down approach
int max_profit(vector<int>& bottle,int i,int j,int dp[50][50],int y){
    if(i>j) return 0;
    if(dp[i][j]!=0) return dp[i][j];
    int op1 = INT_MIN;int op2 =  INT_MIN;
    op1 = bottle[i]*y + max_profit(bottle,i+1,j,dp,y+1);
    op2 = bottle[j]*y + max_profit(bottle,i,j-1,dp,y+1);
    dp[i][j] = max(op1,op2);
    return dp[i][j];
}
int main(){
    int n;
    cin>>n;
    vector<int> bottle(n);
    for(int i=0;i<n;i++) cin>>bottle[i];
    int dp[50][50]={0};
    cout<<max_profit(bottle,0,n-1,dp,1);
    //bottom up approach
    
    return 0;
}