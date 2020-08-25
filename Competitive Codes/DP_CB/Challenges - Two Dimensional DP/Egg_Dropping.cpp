/*
https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/
*/

#include <bits/stdc++.h>
using namespace std;
#define N 5000
#define ll long long
#define INF 100000000099ll
ll dp[N][N];
//solve(floors,eggs)
int solve(int n,int k){
    if(n==-1)return INT_MIN;
    if(n==1)return 1;
    if(k==1)return n;
    if(dp[n][k]!=-1)return dp[n][k];
    int ans=INF;
    for(int i=0;i<n;i++){
        ans = min(ans,max(solve(n-i,k),solve(i-1,k-1)));
    }
    dp[n][k] = ans+1;
    return ans;
}

int main() {
	int n,k;
	cin>>n>>k;
	for(int i=0;i<N;i++)
	    for(int j=0;j<N;j++)
	        dp[i][j] = -1;
	cout<<solve(n,k);
	//dp[eggs][floors]
	//bottom up
	ll dp[k+1][n+1];
	for(int i=1;i<=n;i++)dp[0][i] = i;  //for one egg
	for(int i=1;i<=k;i++)dp[i][0] = 1; //for one floor and i eggs only one attempt req.
	for(int i=2;i<=k;i++){
	    for(int j=2;j<=n;j++){
	        dp[i][j] = INT_MIN;
	        for(int x=1;x<=j;x++){ // floors
	            //max(critical floor upwards => egg doesn't break,critical floor downwards => egg breaks)
	            int subpr = 1 + max(dp[i][j-x],dp[i-1][x-1]);
	            dp[i][j] = min(dp[i][j],subpr);
	        }
	    }
	}
	cout<<dp[n][k];
	return 0;
}




