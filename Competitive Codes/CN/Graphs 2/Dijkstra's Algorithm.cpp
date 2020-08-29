/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices 
(which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices 
(including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. 
Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi,
denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int getVertex(vector<bool>& visited,vector<int>& distance,int n){
    int minVertex = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] and (minVertex==-1 or distance[minVertex] > distance[i])){
            minVertex = i;
        }
    }
    return minVertex;
}
void prims(vector<vector<int>>& edge,int n){
    vector<bool> visited(n,false);
    vector<int> distance(n,INT_MAX);
    distance[0] = 0;
    for(int i=0;i<n-1;i++){
        int minVertex = getVertex(visited,distance,n);
        visited[minVertex] = true;
        for(int j=0;j<n;j++){
            if(!visited[j] and edge[minVertex][j]){
               int curD = distance[minVertex] + edge[minVertex][j];
                if(distance[j] > curD){
                    distance[j] = curD;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" "<<distance[i]<<"\n";
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
