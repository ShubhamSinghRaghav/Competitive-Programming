/*
Given a graph with N vertices (numbered from 1 to N) and 
Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , 
then count the distinct 3-cycles in the graph. 
A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Return Format :
The count the number of 3-cycles in the given Graph
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Sample Input:
3 3
1 2 3
2 3 1
Sample Output:
1
*/

int check(vector<vector<int>>& cycle,int i,int n,vector<bool>& visited){
    int c=0;
    for(int j=1;j<n+1;j++){
        if(!visited[j] and cycle[i][j]==1){
         //   cout<<"*";
            for(int k=1;k<n+1;k++){
                if(!visited[k] and cycle[k][i]==1 and cycle[j][k]==1){ c++;         
                }
            }
        }
    }
    //cout<<c<<" ";
    return c/2;
}
int solve(int n,int m,vector<int>u,vector<int>v){
    vector<vector<int>> cycle(n+1,vector<int>(n+1,0));
    int j=0;
    while(m--){
        cycle[u[j]][v[j]]=1;
        cycle[v[j]][u[j]]=1;
        j++;
    }
    vector<bool> visited(n+1,false);
    int sum=0;
    for(int i=1;i<n+1;i++){
        visited[i] = true;
         sum += check(cycle,i,n,visited); 
    }
    return sum;
}