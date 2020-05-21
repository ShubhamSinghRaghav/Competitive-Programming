#include<bits/stdc++.h>
using namespace std;
bool vis[1001];
vector<int> g[1001];
void bfs(int s,vector<int> adj[],bool vis[]);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(g,0,sizeof g);
        memset(vis,false,sizeof vis);
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
        }
        bfs(1,g,vis);
        cout<<endl;
    }
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* You have to complete this function*/
void bfs(int s,vector<int> adj[],bool vis[]){
    vis[s]=true;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int temp = q.front();
        cout<<temp<<" ";
        q.pop();
        for(auto i:adj[temp]){
            if(!vis[i]){
                q.push(i);
                vis[i]=true;
            }
        }
    }
}
