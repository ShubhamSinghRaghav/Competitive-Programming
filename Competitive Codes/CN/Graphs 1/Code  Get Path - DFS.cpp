/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), 
find and print the path from v1 to v2 (if exists). 
Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, 
denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
*/

#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
stack<int> sk;
int x,y;
void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfs(vector<int> adj[],int s){
    sk.push(s);
    if(s==y){
        while(!sk.empty()){
            cout<<sk.top()<<" ";
            sk.pop();
        }
    }
    visited[s] = true;
    for(auto i:adj[s]){
        if(!visited[i]) dfs(adj,i);
    }
    if(!sk.empty())
    	sk.pop();
}
int main() {
    int n,q;
    cin>>n>>q;
    vector<int> adj[n];
    while(q--){
        int u,v;
        cin>>u>>v;
        addedge(adj,u,v);
    }
    for(int i=0;i<n;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    visited.resize(n,false);
    cin>>x>>y;
    dfs(adj,x);
    return 0;
}
