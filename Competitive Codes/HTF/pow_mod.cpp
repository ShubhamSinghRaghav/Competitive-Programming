#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll power(ll a,ll p,ll mod){
	if(p==0) return 1;
	ll sa = power(a,p/2,mod);
	sa = (sa * sa)%mod;
	if(p%2==1){
		sa = (sa * a)%mod;
	}
	return sa;
}

long long pow_(ll a, ll b)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}

int main(){
	return 0;
}