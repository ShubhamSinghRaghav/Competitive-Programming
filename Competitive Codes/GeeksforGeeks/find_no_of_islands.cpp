int row[]=   {0, 0,1,-1,1,1,-1,-1};
int column[]={1,-1,0,0, 1,-1,1,-1};
void dfs(int arr[MAX][MAX],int a,int b,int visited[60][60]){
    visited[a][b]=1;
    for(int i=0;i<8;i++){
        if(visited[row[i]+a][column[i]+b]==0 and arr[row[i]+a][column[i]+b]==1){
            dfs(arr,row[i]+a,column[i]+b,visited);
        }
    }
}
int findIslands(int arr[MAX][MAX], int n, int m){
    int visited[60][60]={0};
    /*for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            visited[i][j]=0;
        }
    }*/int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==0 and arr[i][j]==1){
                dfs(arr,i,j,visited);
                ans++;
            }
        }
    }
    return ans;
}
