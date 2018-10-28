#include <bits/stdc++.h>
using namespace std;
int main(){
	int x,y,z,t1,t2,t3;
	cin>>x>>y>>z>>t1>>t2>>t3;
	int ts=abs(x-y)*t1;
	int te=abs(x-z)*t2+3*t3+abs(x-y)*t2;
	//cout<<ts<<" "<<te<<"\n";
	if(te<=ts) cout<<"YES";
	else cout<<"NO";
		return 0;
}
