#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        int dp[n][m]={0};
        for(int j=m-1;j>=0;j--){
            for(int i=0;i<n;i++){
                int r = (j==m-1) ?0: dp[i][j+1];
                int r_u = (i==0 or j==m-1 )?0:dp[i-1][j+1];
                int r_d = (i==n-1 or j==m-1 )?0:dp[i+1][j+1];
                dp[i][j] = a[i][j]+max(r,max(r_u,r_d));
            }
        }
        // for(int i=0;i<n;i++){
            // for(int j=0;j<m;j++)
                // cout<<dp[i][j]<<" ";cout<<"\n";}
                
        int maxa=dp[0][0];
        for(int i=1;i<n;i++){
            maxa = max(maxa,dp[i][0]);
        }
        cout<<maxa<<"\n";
    }
	return 0;
}