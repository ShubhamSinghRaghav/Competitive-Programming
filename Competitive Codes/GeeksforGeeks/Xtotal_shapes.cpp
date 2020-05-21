using namespace std;
#define ll long int

void dfs(int arr[120][120],int a,int b,int visited[120][120]){
        visited[a][b]=1;
        int row[]={0,0,-1,1};
        int column[]={-1,1,0,0};
        for(int i=0;i<4;i++){
            if(arr[a+row[i]][b+column[i]]==1 && visited[a+row[i]][b+column[i]]==0)
                dfs(arr,a+row[i],b+column[i],visited);
        }
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;cin>>n>>m;
	    int a[120][120]={0};
	    int visited[120][120]={0};
	    vector<string> s(n);
	    for(int i=0;i<n;i++){
	        cin>>s[i];
	        for(int j=0;j<s[i].size();j++){
	            if(s[i][j]=='X') a[i][j]=1;
	        }
	    }
	    int counter=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(a[i][j]==1 && visited[i][j]==0){
	                dfs(a,i,j,visited);
	                counter++;
	            }
	        }
	    }
	    cout<<counter<<endl;
	}
	return 0;
}
