/*
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. 
And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). 
Order of different components doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
Different components in new line
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/

#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<int> res;
void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfs(vector<int> adj[],int s){
    res.push_back(s);
    visited[s] = true;
    for(auto i:adj[s]){
        if(!visited[i]) dfs(adj,i);
    }
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
    visited.resize(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(adj,i);
            sort(res.begin(),res.end());
            for(auto j:res) cout<<j<<" ";cout<<"\n";
            res.clear();
        }
    }
  return 0;
}
