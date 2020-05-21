#include<bits/stdc++.h>
using namespace std;

bool check(int a[],int m,int n){
    if(n>m) return true;
    vector<bool> dp(m,false);
    for(int i=0;i<n;i++){
        if(dp[0]) return true;
        vector<bool> temp(m,false);
        for(int j=0;j<m;j++){
            if(dp[j]==true){
                if(dp[(j+a[i])%m]==false)
                    temp[(j+a[i])%m]=true;
            }
        }
        for(int j=0;j<m;j++) if(temp[j]) dp[j]=true;
        dp[a[i]%m]=true;
    }
    return dp[0];
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int a[n];
	    
	    for(int i=0;i<n;i++) cin>>a[i];
	    if(check(a,m,n)) cout<<"1\n";
	    else cout<<"0\n";
	    
	}
	return 0;
}