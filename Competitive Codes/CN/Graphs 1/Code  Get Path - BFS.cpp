/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), 
find and print the path from v1 to v2 (if exists). 
Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
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
int x,y;
int m[1001];
void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void solve(int s){
    if(m[s]==-1)return;
    cout<<m[s]<<" ";
    solve(m[s]);
}
int main(){
    int n,qq;
    cin>>n>>qq;
    vector<int> adj[n];
    while(qq--){
        int u,v;
        cin>>u>>v;
        addedge(adj,u,v);
    }
    for(int i=0;i<n;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    vector<bool> visited(n,false);
    cin>>x>>y;
    memset(m,-1,sizeof(m));
    visited[x] = true;
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int k = q.front();
        int len = q.size();
        q.pop();
        while(len--){
            for(auto p:adj[k]){
                if(!visited[p]){
                    visited[p] = true;
                    m[p] = k; 
                    if(p==y){
                        cout<<y<<" ";
                        solve(y);
                        return 0;
                    }
                    q.push(p);
                }
            }
        }
    }
    return 0;
}
