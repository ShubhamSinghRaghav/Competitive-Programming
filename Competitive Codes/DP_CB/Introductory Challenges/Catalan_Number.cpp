//catalan Numbers
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
int main() {
	ll n;
	cin>>n;
	ll dp[n+1]={0};
	dp[0]=1;
	dp[1]=1;
	for(ll i=2;i<n+1;i++){
		dp[i]=0;
		for(int j=i;j>=0;j--){
			dp[i] += dp[j]*dp[i-j-1];
		}
	}
	cout<<dp[n];
	return 0;
}