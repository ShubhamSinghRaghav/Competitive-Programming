//https://practice.geeksforgeeks.org/problems/topological-sort/1
void dfs_topo(vector<int> adj[],int a,int visited[],stack<int> &res){
    visited[a]=1;//int save;
    vector<int>::iterator i; 
    for (i = adj[a].begin(); i != adj[a].end(); ++i) {
        if(visited[*i]==0)
            dfs_topo(adj,*i,visited,res);
    }
    res.push(a);
}

int * topoSort(vector<int> adj[], int n){
   int *result = new int[n];int j=0;
   //vector<int> visited(n,0);
   int visited[n]={0};
   stack<int> res;
   for(int i=0;i<n;i++){
       if(!visited[i]){
           dfs_topo(adj,i,visited,res);
       }
   }
   while(res.empty()==false){
       result[j++]=res.top();
       res.pop();
   }
   return result;
}
