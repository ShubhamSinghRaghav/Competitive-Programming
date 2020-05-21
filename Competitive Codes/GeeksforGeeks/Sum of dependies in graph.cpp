#include <bits/stdc++.h>
#define pb push_back
using namespace std;

void addedge(vector<int> adj[],int u,int v){
    adj[u].pb(v);
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,e;
	    cin>>n>>e;
	    vector<int> adj[n];
	    while(e--){
	        int x,y;
	        cin>>x>>y;
	        addedge(adj,x,y);
	    }
	    int sum=0;
	    for(auto i:adj)sum+=i.size();
	    cout<<sum<<"\n";
	}
	return 0;
}
