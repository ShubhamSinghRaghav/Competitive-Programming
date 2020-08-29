/*
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . 
A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. 
Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
Constraints :
1<=N<=50
Input Format :
Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake
Output Format :
Size of the biggest piece of '1's and no '0's
Sample Input :
2
11
01
Sample Output :
3
*/


int maxa;
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};
void dfs(char a[NMAX][NMAX],int r,int c,int n,vector<vector<bool>>& visited){
    if(r==n or c==n or visited[r][c])return;
    visited[r][c] = true;
    maxa++;
    for(int i=0;i<4;i++){
        if(a[r+dr[i]][c+dc[i]]=='1')
        dfs(a,r+dr[i],c+dc[i],n,visited);
    }
}

int solve(int n,char a[NMAX][NMAX]){
    int res=0;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]=='1' and !visited[i][j]){
                maxa = 0;
                dfs(a,i,j,n,visited);
                res = max(maxa,res);
            }
        }
    }
    return res;
}