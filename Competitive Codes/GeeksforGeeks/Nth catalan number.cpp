#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using boost::multiprecision::cpp_int; 
using namespace std;
#define ll int 
int main() {
    cpp_int dp[101]={0};
    dp[0]=1;
    for(int i=1;i<101;i++){
        for(int j=0;j<i;j++){
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<dp[n]<<"\n";
    }
	return 0;
}