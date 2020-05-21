#include <bits/stdc++.h>
using namespace std;
bool final=false;int n;
void dfs(int a,int b,int visited[30][30],int arr[30][30]){
    visited[a][b]=1;
    if(b-1>=0 and arr[a][b-1]==2){
       // cout<<"Block1\n";
        final = true;
        return;
    }if(b+1<n and arr[a][b+1]==2){
    //    cout<<"Block2\n";
        final = true;
        return;
    }if(a-1>=0 and arr[a-1][b]==2){
      //  cout<<"Block3\n";
        final = true;
        return;
    }if(a+1<n and arr[a+1][b]==2){
    //    cout<<"Block4\n";
        final = true;
        return;
    }
    // if(arr[a][b]==2){
    //     final = true;
    //     return;
    // }
    int row[]={1,-1,0,0};
    int column[]={0,0,1,-1};
    for(int i=0;i<4;i++){
        if(visited[row[i]+a][column[i]+b]==0 and arr[row[i]+a][column[i]+b]==3){
            dfs(a+row[i],b+column[i],visited,arr);
        }
    }
    //return;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    final=false;
	    //int n;
	    cin>>n;
	    int a[30][30]={0};
	    int visited[30][30]={0};
	    int pos_x=0,pos_y=0;
	    for(int i=0;i<n;i++){
	       for(int j=0;j<n;j++){
	           cin>>a[i][j];
	           if(a[i][j]==1){
	               pos_x=i;pos_y=j;
	           }
	       }
	    }
	    
	    dfs(pos_x,pos_y,visited,a);
	    cout<<final<<"\n";
	}
	return 0;
}
