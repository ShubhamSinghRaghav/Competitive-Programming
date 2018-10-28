#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		vector<pair<int,int> > g;
		int n,m;cin>>n>>m;
		for(int i=0;i<n;i++){
		    string s;
		    cin>>s;
			for(int j=0;j<s.size();j++){
				if(s[j]=='1') g.push_back(make_pair(i,j));
			}
		}
	//	cout<<g.size();
		int reso[n+m]={0};
		for(int i=0;i<g.size();i++){
			for(int j=i+1;j<g.size();j++){
				int D=abs(g[i].first-g[j].first)+abs(g[i].second-g[j].second);
				reso[D]+=1;
			}
		}
		for(int i=1;i<=n+m-2;i++) cout<<reso[i]<<" ";
	}	
	return 0;
}

