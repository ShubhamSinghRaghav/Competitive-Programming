#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int visited[51];
vector<int> edges[51];
int gcd(int a,int b){ 
    if(b==0) return a;
    else return gcd(b,a%b);
} 

void dfs(int s){
    visited[s]=1;
    //for(int i=edges[s];i<edges[s].size();i++) if(visited[i]==0) dfs(i);
    for(auto i:edges[s]) if(visited[i]==0) dfs(i);
}

int main(){
	int t;
	cin>>t;
	while(t--){ 
	    bool flag=true;
		//map<int,int> mapper;
		int mapper[51]={0};
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
			mapper[a[i]]++;
		}
		for(int i=0;i<51;i++){
			visited[i]=0;
			edges[i].clear();
		}
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(gcd(a[i],a[j])==1) 
					edges[i].pb(j), edges[j].pb(i);
		dfs(0);
		for(int i=0;i<n;i++){ 
			if(visited[i]==0){
				cout<<"1"<<"\n";
        
             if(mapper[37]>=1)
              a[0]=41;
             else
              a[0]=37;
        
            for(i=0;i<n;i++)
            cout<<a[i]<<" ";
            flag=false;
			}
		}
		if(flag){  
		cout<<"0"<<"\n";
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        } 
        cout<<"\n";		
	}
	return 0;
} 
