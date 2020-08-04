#include <bits/stdc++.h>
#include <sstream>
using namespace std;
unordered_map<string,int> mp;
unordered_map<int,string> rmp;
unordered_map<int,int> mp_pro;
struct node{
    int dest;
    int weight;
    bool reverse;
};
void addedge(vector<node> adj[],int s,int e,int val){
    node save;
    save.dest = e;
    save.weight = val;
    save.reverse = false;
    adj[s].push_back(save);
    save.dest = s;
    save.reverse = true;
    adj[e].push_back(save);
}
vector<string> splitter(string ss){
    vector<string> input;
	int pos = 0, word = 0,len=0;
	for(int i=0;i<ss.size();i++){
	    len++;
	    if(ss[i]==' '){
	       input.push_back(ss.substr(pos,len-1));
	       len=0;
	       pos=i+1;
	    }
	}
	return input;
}

void dfs(vector<node> adj[],int s,vector<bool>& visited,vector<string>& result){
    visited[s] = true;
    for(auto noder:adj[s]){
        if(!visited[noder.dest]){
            
            if(noder.reverse) mp_pro[noder.dest] =mp_pro[s] / noder.weight;
            else mp_pro[noder.dest] =mp_pro[s] * noder.weight;
           
            ostringstream numtostring;
            numtostring<<mp_pro[noder.dest];
            string save ="";
            save += numtostring.str();
            save += rmp[noder.dest];
            result.push_back(save);
            dfs(adj,noder.dest,visited,result);
        }
    }
}

int main(){
    int n;
    cin>>n;
    string point[n];
    int kk = 0;
    int savo = n;
    while(savo--){
        cin>>point[kk];
        kk++;
    }
    
    int k=0;
    for(auto i:point) mp[i] = k++;
    k=0;
    for(int i=0;i<n;i++) rmp[i] = point[k++];
    vector<node> adj[n];
    int fill_nodes = n;
    int leave = 0;
    while(fill_nodes--){

        string s;
        getline(cin,s);
        if(leave==0){leave++;continue;}
        s+=" ";
        
        vector<string> ss = splitter(s);
        stringstream geek(ss[2]); 
        int val = 0; 
        geek >> val;
        
        addedge(adj,mp[ss[0]],mp[ss[3]],val);
    }
    
    for(int i=0;i<n;i++){
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++) mp_pro[i] = 1;
        vector<string> result;
        dfs(adj,i,visited,result);
        sort(result.begin(),result.end());
        if(result[0][0]!='0'){
            cout<<"1"<<rmp[i]<<" ";
            for(auto i:result)cout<<" = "<<i<<" ";
            break;
        }
    }
	return 0;
}