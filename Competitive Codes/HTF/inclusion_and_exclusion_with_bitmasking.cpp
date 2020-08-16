#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        
        int primes[]={2,3,5,7,11,13,17,19};
        ll subsets = 1<<8;
        ll ans =0ll;
        for(int i=1;i<subsets;i++){
            ll denom= 1ll;
            ll setbits = __builtin_popcount(i);
            for(int j=0;j<8;j++){
                if(i&(1<<j)){
                    denom = denom * primes[j];
                }
            }
            if(setbits&1){
                ans += n/denom;
            }else{
                ans -= n/denom;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
