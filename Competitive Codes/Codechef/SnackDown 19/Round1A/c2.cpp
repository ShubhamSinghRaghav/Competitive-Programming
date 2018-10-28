#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		vector<long int> v(n);
		for(int i=0;i<n;i++) cin>>v[i];
		long int countT=0,countF=0,pos=0;
		for(int i=0;i<n-1;i++){
			if(v[i]<=v[i+1]) countT++;
			else {pos=i;
				countF++;
			}
		}
		if(countF<=1 ){
		    if(countF==0) cout<<"YES\n";
		    else if(v[0]<=v[n-1] && countF==1) cout<<"YES\n";
		    else cout<<"NO\n";
		}
		else cout<<"NO\n";
	}
	return 0;
}
