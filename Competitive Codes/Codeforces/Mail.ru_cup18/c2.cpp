#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	long int a[n];
	int pos=-1;bool flag=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==0 && a[i]!=0 && flag){
			flag=false;
			pos=i+1;
		}
//		else if(i==1 && a[i]!=1 && flag){
//			flag=false;
//			pos=i+1;
//		}
		else if(flag && i>0){
			if(a[i]>i){
			flag=false;
			pos=i+1;
			}
			}
	}
	cout<<pos;
	return 0;
}
