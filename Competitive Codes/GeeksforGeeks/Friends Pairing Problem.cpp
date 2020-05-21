#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define mod 1000000007
int main() {
    ll dp[101]={0};
    dp[1]=1;dp[2]=2;
    for(int i=3;i<101;i++) dp[i] = (dp[i-1] + (i-1)*dp[i-2])%mod;
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    cout<<dp[n]<<"\n";
	}
	return 0;
}