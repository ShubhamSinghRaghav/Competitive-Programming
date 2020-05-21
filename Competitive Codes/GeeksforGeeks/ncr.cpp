#include<bits/stdc++.h>
using namespace std;
// #include <boost/multiprecision/cpp_int.hpp> 
// using boost::multiprecision::cpp_int; 
#define MAX 1000000007
#define ll unsigned long long int
ll ncr(int n,int r){
    ll dp[n+1][r+1];
    dp[0][0]=1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,r);j++){
            if(i==j or j==0) dp[i][j]=1;
            else dp[i][j]=(dp[i-1][j] + dp[i-1][j-1])%MAX;
        }
    }
    return (dp[n][r]);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,r;
        cin>>n>>r;
        if(n>=r)
        cout<<ncr(n,r)<<"\n";
        else cout<<"0\n";
    }
	return 0;
}