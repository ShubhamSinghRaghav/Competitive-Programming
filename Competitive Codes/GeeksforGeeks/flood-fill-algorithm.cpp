//https://practice.geeksforgeeks.org/problems/flood-fill-algorithm/0
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
//int r,c;
int row[]={0,0,1,-1};
int col[]{1,-1,0,0};
void dfs(int arr[100][100],int a,int b,int visited[100][100],int save,int value){
    visited[a][b]=1;
    arr[a][b]=value;
    for(int i=0;i<4;i++){
        if(visited[a+row[i]][b+col[i]]==0 and arr[a+row[i]][b+col[i]]==save){
            dfs(arr,a+row[i],b+col[i],visited,save,value);
        }
    }
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int r,c;
	    cin>>r>>c;
	    int arr[100][100];
	    int visited[100][100]={0};
	    for(int i=0;i<r;i++)
	        for(int j=0;j<c;j++)
	            cin>>arr[i][j];
	   int x,y;cin>>x>>y;
	   int value;
	   cin>>value;
	    int save = arr[x][y];
	    dfs(arr,x,y,visited,save,value);
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            cout<<arr[i][j]<<" ";
	            }
	            //cout<<"\n";
	        }
	        //cout<<"\n";
	    
	    cout<<"\n";
	}
	return 0;
}
