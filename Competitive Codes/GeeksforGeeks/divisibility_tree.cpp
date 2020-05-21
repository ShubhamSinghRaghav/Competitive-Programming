#include <vector>
#include <cstring>
using namespace std;

vector<int> v[1001];
int size[1001];
int vis[1001];
int ans=0;

int dfs(int i)
{
    int count=1;
    vis[i]=1;
    for(int j=0; j<size[i];++j)
    {
        if(vis[v[i][j]])
        continue;
        
        int cnt = dfs(v[i][j]);
        if(cnt%2!=0)
        count += cnt;
        else
        ++ans;
    }
   
    return count;
}

int main() {
	//code
	int t,p,q,x,y;
	cin>>t;
	
	while(t--)
	{
	    memset(size,0,1001*sizeof(int));
	    memset(vis,0,1001*sizeof(int));
	    for(int i=0; i<1001;++i)
	    v[i].clear();
	    ans=0;
	    cin>>p>>q;
	    for(int i=0; i<q;++i)
	    {
	        cin>>x>>y;
	        v[x].push_back(y);
	        v[y].push_back(x);
	        ++size[y], ++size[x];
	    }
	    for(int i=1; i<=p;++i)
	    {
	        if(vis[i])
	        continue;
	        dfs(i);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
///////////////////////////////
/*

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 100000
bool visited[MAX];
//vector<int> adj[MAX];
int ans=0;
void addedge(vector<int> adj[],int x,int y){
    adj[x].pb(y);
    adj[y].pb(x);
}

int dfs(int s,vector<int> adj[]){
    visited[s]=true;
    int count=1;
    for(auto i:adj[s]){
        if(visited[i]) continue; 
        
        int c = dfs(i,adj);
        if(c%2!=0) count+=c;
        else ans++;
    }
    return count;
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<MAX;i++){
	    visited[i]=false;
	}
	while(t--){
	    int n,e;
	    cin>>n>>e;
	    vector<int> adj[n];
	    while(e--){
	        int x,y;
	        cin>>x>>y;
	        addedge(adj,x,y);
	    }
	   for(int i=1;i<=n;i++){
	       if(visited[i])continue;
	       dfs(i,adj);
	   } 
	   cout<<ans<<"\n";
	}
	return 0;
}

*/


