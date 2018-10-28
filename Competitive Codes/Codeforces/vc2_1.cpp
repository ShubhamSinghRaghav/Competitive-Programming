#include <bits/stdc++.h>
using namespace std;

int main(){
	int t,ii=0;
	cin>>t;
	int maxer=-1001;
	string res;
	map<string,int> m;
	while(t--){
		int n;
		string s;
		cin>>s>>n;
		
		if(m.find(s)!=m.end()){
			m[s]+=n;
		    	
		}else
		m.insert(pair<string,int> (s,n));
		if(maxer<m[s]) {maxer=m[s];
		    res=s;
		    }
	}
	cout<<res;
// 	    int maxa=-1001;
// 		for (std::map<string,int>::iterator it=m.begin(); it!=m.end(); ++it){
// 			if(maxa<it->second) maxa=it->second;
// 		}
// 		for (std::map<string,int>::iterator it=m.begin(); it!=m.end(); ++it){
// 			if(maxa==it->second){
// 			//	cout<<it->first;
// 				break; 
// 			}
// 		}
	return 0;
}
