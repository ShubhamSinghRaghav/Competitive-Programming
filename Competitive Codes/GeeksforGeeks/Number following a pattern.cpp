#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int len = s.size();
	    stack<int> sos;
	    vector<int> v;
	    for(int i=0;i<=len;i++){
	       sos.push(i+1);
	       if(s[i]=='I' || i==len){
	           while(!sos.empty()){
	               v.push_back(sos.top());
	               sos.pop();
	           }
	       }
	    }
	    for(int i=0;i<v.size();i++){
	        cout<<v[i];
	    }
	    cout<<"\n";
	}
	return 0;
}
