#include <bits/stdc++.h>
using namespace std;

int main(){
	string s,t;
	cin>>s>>t;
	bool flag=false;
	if(s[0]<t[0]){
		if(s[1]<t[1]){
			
			int x= t[1]-s[1];
			int k=t[0]-s[0];
			if(abs(s[0]-t[0])<abs(s[1]-t[1])) flag=true,swap(x,k);
			s[0]+=x;
			if(!(flag))
			k=t[0]-s[0];
			if(!(flag))
			cout<<x+k<<"\n";
			else
			k-=x,cout<<x+k<<"\n";
			while(x--) cout<<"RU\n";
			if(!(flag))
			while(k--) cout<<"R\n";
			else
			while(k--) cout<<"U\n";
		}
		else if(s[1]>t[1]){
			int x= s[1]-t[1];
			int k=t[0]-s[0];
			if(abs(s[0]-t[0])<abs(s[1]-t[1])) flag=true,swap(x,k);
			s[0]+=x;
			if(!(flag))
			k=t[0]-s[0];
			if(!(flag))
			cout<<x+k<<"\n";
			else
			k-=x,cout<<x+k<<"\n";
			while(x--) cout<<"RD\n";
			if(!(flag))
			while(k--) cout<<"R\n";
			else
			while(k--) cout<<"D\n";
		}
		else{
			int k=t[0]-s[0];
			cout<<k<<"\n";
			while(k--) cout<<"R\n";
		}
	}
	else if(s[0]>t[0]){
		if(s[1]<t[1]){
			int x= t[1]-s[1];
			int k=-t[0]+s[0];
			if(abs(s[0]-t[0])<abs(s[1]-t[1])) flag=true,swap(x,k);
			t[0]+=x;
			if(!(flag))
			k=-t[0]+s[0];
			if(!(flag))
			cout<<x+k<<"\n";
			else
			k-=x,cout<<x+k<<"\n";
			while(x--) cout<<"LU\n";
			if(!(flag))
			while(k--) cout<<"L\n";
			else
			while(k--) cout<<"U\n";
		}
		else if(s[1]>t[1]){
			int x= s[1]-t[1];
			int k=-t[0]+s[0];
			if(abs(s[0]-t[0])<abs(s[1]-t[1])) flag=true,swap(x,k);
			t[0]+=x;
			if(!(flag))
			k=-t[0]+s[0];
			if(!(flag))
			cout<<x+k<<"\n";
			else
			k-=x,cout<<x+k<<"\n";
			while(x--) cout<<"LD\n";
			if(!(flag))
			while(k--) cout<<"L\n";
			else
			while(k--) cout<<"D\n";
		}
		else{
			int k=-t[0]+s[0];
			cout<<k<<"\n";
			while(k--) cout<<"L\n";
		 }
		}
		else{
			if(t[1]>s[1]){
				int x=t[1]-s[1];
				cout<<x<<"\n";
				while(x--) cout<<"U\n";
			}
			else{
				int x=-t[1]+s[1];
				cout<<x<<"\n";
				while(x--) cout<<"D\n";
			}
		}
	return 0;
}
