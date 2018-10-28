#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int count=0;
		for(int i=0;i<30;i++){
			int x;cin>>x;
			if(x==1){
				count++;
				if(count>5) break;
			}
			else{
				count=0;
			}
		}
		if(count>5) cout<<"#coderlifematters\n";
		else cout<<"#allcodersarefun\n";
	}
	return 0;
}
