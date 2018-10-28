#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long int
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		ll a[n],sum=0;
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		if(n==1)
		{
			cout<<sum<<endl;
			continue;
		}
		sort(a,a+n);
		ll start=0;
		for(ll i=0;i<=n-2;i++)
		{
			if(a[i]<=k)
				start++;
		}
		ll d=0;
		for(ll j=start;j<=n-2;j++)
		{
			d+=(a[j]-k);
		}
		if(d%2==0)
		{
			sum-=d;
		}
		else
		{
			sum-=(d+1);
		}
		cout<<sum<<endl;
	}
}
