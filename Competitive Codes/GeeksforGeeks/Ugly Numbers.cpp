#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ll dp[10001]={0};
    dp[0]=1;
    int i2=0,i3=0,i5=0;
    ll next_2 = dp[i2]*2;
    ll next_3 = dp[i3]*3;
    ll next_5 = dp[i5]*5;
    ll ugl;
    for(int i=1;i<10001;i++){
        ugl = min(next_2,min(next_3,next_5));
        dp[i] = ugl;
        if(ugl == next_2){
            i2++;
            next_2=dp[i2]*2;
        }
        if(ugl == next_3){
            i3++;
            next_3=dp[i3]*3;
        }
        if(ugl == next_5){
            i5++;
            next_5=dp[i5]*5;
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<dp[n-1]<<"\n";
    }
	return 0;
}