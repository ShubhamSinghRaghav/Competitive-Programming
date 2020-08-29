/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices 
(which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST
 and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, 
denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
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
1 2 1
0 1 3
0 3 5
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long
struct node{
    int src;
    int dest;
    int wt;
};
bool check(node a,node b){
    return a.wt<b.wt;
}
int getParent(int parent[],int v){
    if(parent[v] == v) return v;
    return getParent(parent,parent[v]);
}
int main(){
    int n;
    cin>>n;
    int m;cin>>m;
    node edge[m];
    for(int i=0;i<m;i++){
        cin>>edge[i].src>>edge[i].dest>>edge[i].wt;
    }
    sort(edge,edge+m,check);
 //   for(int i=0;i<n;i++) cout<<edge[i].src<<" "<<edge[i].dest<<" "<<edge[i].wt<<"\n";
    int count=0;
    int parent[n];
    for(int i=0;i<n;i++) parent[i] = i;
    int j = 0;
    vector<node> res;
    while(count!=n-1){
        int src_p = getParent(parent,edge[j].src);
        int dest_p = getParent(parent,edge[j].dest);
        if(src_p != dest_p){
            count++;
            parent[dest_p] = src_p;
            res.push_back(edge[j]);
        }
        j++;
    }
    for(auto i:res){
        if(i.src > i.dest)
        	cout<<i.dest<<" "<<i.src;
        else cout<<i.src<<" "<<i.dest;
            cout<<" "<<i.wt<<"\n";
    }
    return 0;
}
