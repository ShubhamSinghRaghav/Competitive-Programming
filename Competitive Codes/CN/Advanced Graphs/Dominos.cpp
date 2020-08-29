/*
Domino
Dominos are lots of fun. Children like to stand the tiles on their side in long lines. 
When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line.
However, sometimes a domino fails to knock the next one down. 
In that case, we have to knock it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, 
the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.
Input
The first line of input contains one integer specifying the number of test cases to follow.
Each test case begins with a line containing two integers,each no larger than 100 000. 
The first integer n is the number of domino tiles and the second integer m is the number of lines to follow in the test case. 
The domino tiles are numbered from 1 to n.
Each of the following lines contains two integers x and y indicating that if domino number x falls, 
it will cause domino number y to fall as well.
Output
For each test case, output a line containing one integer, 
the minimum number of dominos that must be knocked over by hand in order for all the dominos to fall.
Sample Input
1
3 2
1 2
2 3
Sample Output
1
*/

#include <bits/stdc++.h>
using namespace std;
void addedge(vector<int> adj[],int a,int b){
    adj[a].push_back(b);
}

void dfs(vector<int> adj[],stack<int>& st,vector<bool>& visited,int s){
    visited[s] = true;
    for(auto i : adj[s]){
        if(!visited[i]){
            dfs(adj,st,visited,i);
        }
    }
    st.push(s);
}
void dfs2(vector<int> adj[],stack<int>& st,vector<bool>& visited,int s){
    visited[s] = true;
    for(auto i : adj[s]){
        if(!visited[i]){
            dfs(adj,st,visited,i);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){ 
        stack<int> st;
        int n,q;
        cin>>n>>q;
        vector<bool> visited(n+1,false);
        vector<int> adj[n+1];
        for(int i=0;i<q;i++){
            int a,b;
            cin>>a>>b;
            addedge(adj,a,b);
        }
        for(int i=1;i<=n;i++){
            if(visited[i]==0){
                dfs(adj,st,visited,i);
            }
        }
        int tot=0;
        for(int i=1;i<=n;i++) visited[i] = false;
        while(!st.empty()){
            int x = st.top();
            if(!visited[x]){
                tot++;
                dfs2(adj,st,visited,x);
            }
            st.pop();
        }
        cout<<tot<<"\n";
    }
	return 0;
}