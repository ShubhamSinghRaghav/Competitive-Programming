/*
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note : 1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b',
 denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
BFS Traversal (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
*/

#include <bits/stdc++.h>
using namespace std;
void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
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
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
        	cout<<i<<" ";
        	visited[i] = true;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int k = q.front();
                //cout<<k<<" ";
                int len = q.size();
                q.pop();
                while(len--){
                    for(auto p:adj[k]){
                        if(!visited[p]){
                            visited[p] = true;
                        	cout<<p<<" ";
                            q.push(p);
                        }
                    }
                }
            }
    	}
    }
    return 0;
}