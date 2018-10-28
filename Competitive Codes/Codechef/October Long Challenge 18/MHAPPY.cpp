//@shubham_cheenu
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,k) for(int i=0;i<k;i++)
vector<ll> a(100001);
vector<ll> b(100001);
vector<ll> c(100001);
ll n,m,maxa=LLONG_MIN;
int possible(ll medium)
{
    ll balun=m;
    for(int i=0;i<n;i++){
        ll er,f=max((ll)0,c[i]-medium);
        er=(ll)ceil((long double)f/b[i]);
        if(er>balun)
            return 0;
        balun-=er;
    }
    return 1;
}
int main()
{
    cin>>n>>m;
    fr(i,n) cin>>a[i];
    fr(i,n) cin>>b[i], c[i]=a[i]*b[i], maxa=max(maxa,c[i]);
    
    ll l=0,r=maxa,last=r,medium;
      while(l<=r){
        medium=l+(r-l)/2;
        if(possible(medium)){
            r=medium-1;
            last=medium;
        }
        else l=medium+1;
    }
    cout<<last<<endl;
    return 0;
}
