//@shuham_cheenu
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a[100007];
        ll b[100007];
        ll n;
        cin>>n;
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++) cin>>b[i];
        bool flag=true;
        for(ll i=0;i<n-2;i++)
        {
            if(a[i]<b[i])
            {
                ll save=b[i]-a[i];
                a[i]=b[i];
                a[i+1]+=save*2;
                a[i+2]+=save*3;
            }
            else if(a[i]>b[i])
            {
                flag=false;
                break;
            }
        }
        for(ll i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
                flag=false;
                break;
            }
        }
        if(flag)
            cout<<"TAK"<<"\n";
        else
            cout<<"NIE"<<"\n";
    }
    return 0;
}

