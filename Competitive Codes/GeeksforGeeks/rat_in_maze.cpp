//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
int row[]={0,0,1,-1};
int column[]={1,-1,0,0};
void pather(int m[MAX][MAX],int a,int b,int n,int visited[MAX][MAX],string s,vector<string> &result){
    //if(visited[a][b])return;
    //visited[a][b]=1;
    if(a<0 or b<0 or a>=n or b>=n or m[a][b]==0 or m[a][b]==100 ) {
        return ;
    }
    if(a==n-1 and b==n-1){
        result.push_back(s);
    }m[a][b]=100;
    for(int i=0;i<4;i++){
        if(m[a+row[i]][b+column[i]]==1){
            
        //if(visited[a+row[i]][b+column[i]]==0 and m[a+row[i]][b+column[i]]==1){
            if(i==0){
                pather(m,a+row[i],b+column[i],n,visited,s+'R',result);
            }else if(i==1){
                pather(m,a+row[i],b+column[i],n,visited,s+'L',result);
            }else if(i==2){
                pather(m,a+row[i],b+column[i],n,visited,s+'D',result);
            }else{
                pather(m,a+row[i],b+column[i],n,visited,s+'U',result);
            }
        }
    }m[a][b]=1;
}

vector<string> printPath(int m[MAX][MAX], int n){
    vector<string> result;
    int visited[MAX][MAX]={0};
    pather(m,0,0,n,visited,"",result);
   // cout<<result.size()<<" ";
    sort(result.begin(),result.end());
    return result;
}
