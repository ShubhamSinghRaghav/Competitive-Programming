#include <bits/stdc++.h>
using namespace std;
#define ll long long
string bitsreturn(ll n){
	string s;
	for (int i = 30; i >= 0; i--) { 
        int k = n >> i; 
        if (k & 1) 
            s+='1';
			//cout << "1"; 
        else s+='0';
            //cout << "0"; 
    }
    return s;
}

int main(){
	int t;cin>>t;
	while(t--){
		int counter=0;
		ll a,b,c; cin>>a>>b>>c;
		string sa=bitsreturn(a);
		string sb=bitsreturn(b);
		if(b>a)  swap(a,b);
		int pos=0;
		for(int i=0;i<31;i++){
			if(sa[i]==1) pos=i,break;
		}
		int count0=0,count1=0;
		for(i=pos;i<sa.size();i++){
			if(sa[i]!=sb[i]) counter++;
			if(sa[i]==sb[i] && sa[i]==1) count1++;
			if(sa[i]==sb[i] && sa[i]==0) count0++;
		}
		if(count0==0){
			if(count1==0)   cout<<pow(2,counter)-2;
			else   cout<<pow(2,counter)-pow(2,count1);
		}
		else cout<<pow(2,counter)-pow(2,count1)-pow(2,count0);
		cout<<"\n";
	}
	return 0;
}
