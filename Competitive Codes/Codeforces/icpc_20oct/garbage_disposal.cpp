#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ll int n,k;
    cin>>n>>k;
    vector<ll int> v(n+1);
    for(int i=0;i<n;i++) cin>>v[i];
    ll int bags=0,sum=0,leftover=0;
    for(int i=0;i<n;i++){
    	leftover=v[i]%k;
    	if(v[i]<k && i!=n-1){
    		sum=v[i]+v[i+1];
    		if(sum%k==0){
    			bags+=sum/k;
    			i++;
    			continue;
			}
			else{
				bags++;
			}
		}
		bags+=v[i]/k;
	}
    cout<<bags;
    return 0;
}
