/*
An island is a small piece of land surrounded by water .
A group of islands is said to be connected if we can reach from any given island to any other island in the same group .
Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa .
Can you count the number of connected groups of islands.
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Output Return Format :
The count the number of connected groups of islands
Sample Input :
2 1
1
2
Sample Output :
1 
*/

vector<bool> visited;
void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfs(vector<int> adj[],int s){
    visited[s] = true;
    for(auto i:adj[s]){
        if(!visited[i]) dfs(adj,i);
    }
}
int solve(int n,int m,vector<int>u,vector<int>v){
	vector<int> adj[n];
    int j=0;
    while(m--){
        addedge(adj,u[j]-1,v[j]-1);
        j++;
    }
    visited.resize(n,false);
    int islands = 0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            islands++;
            dfs(adj,i);
        }
    }
    return islands;
}




