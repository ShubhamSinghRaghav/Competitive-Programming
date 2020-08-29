/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices 
(which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST 
and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge 
between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
MST
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 1 3
1 2 1
0 3 5
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int getVertex(vector<bool>& visited,vector<int>& weight,int n){
    int minVertex = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] and (minVertex==-1 or weight[minVertex] > weight[i])){
            minVertex = i;
        }
    }
    return minVertex;
}
void prims(vector<vector<int>>& edge,int n){
    vector<bool> visited(n,false);
    vector<int> parent(n);
    vector<int> weight(n,INT_MAX);
    parent[0] = -1;
    weight[0] = 0;
    for(int i=0;i<n-1;i++){
        int minVertex = getVertex(visited,weight,n);
        visited[minVertex] = true;
        for(int j=0;j<n;j++){
            if(!visited[j] and edge[minVertex][j]!=0){
                if(weight[j] > edge[minVertex][j]){
                	weight[j] = edge[minVertex][j];
                	parent[j] = minVertex;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        if(i < parent[i]) cout<<i<<" "<<parent[i]<<" "<<weight[i];
        else cout<<parent[i]<<" "<<i<<" "<<weight[i];
        cout<<"\n";
    }
}
int main(){
    int n,E;
    cin>>n>>E;
    vector<vector<int>> edge(n,vector<int>(n,0));
    for(int i=0;i<E;i++){
        int src,dest,wt;
        cin>>src>>dest>>wt;
        edge[src][dest] = wt;
        edge[dest][src] = wt;
    }
    prims(edge,n);
  return 0;
}
