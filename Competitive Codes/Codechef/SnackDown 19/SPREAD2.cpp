#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005
long int a[MAX];
long int reso[MAX];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int n;
        cin>>n;
        for(long int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(long int i=0;i<=n;i++){
            if(i==0) reso[0]=0;
			reso[i]=a[i]+reso[i-1];
			}
        long int j=1;
        long int ans=0;
        while(j<n)
        {
            j+=reso[j];
            ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

