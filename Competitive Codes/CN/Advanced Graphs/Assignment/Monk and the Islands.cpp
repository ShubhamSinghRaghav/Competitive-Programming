/*
Monk visits the land of Islands. 
There are a total of N islands numbered from 1 to N. 
Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. 
He is standing at Island #1 and wants to reach the Island #N. 
Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.

Input:
First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , 
denoting that there is a bridge between Island X and Island Y.
Output:
Print the answer to each test case in a new line.
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ X, Y ≤ N
SAMPLE INPUT
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
SAMPLE OUTPUT
2
2
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int bfs(vector<int> adj[],int n){
    queue<int> q;
    q.push(1);
    vector<bool> visited(n+1,false);
    visited[1] = true;
    int level = 0;
    while(!q.empty()){
        int len = q.size();
        level++;
        while(len--){
            int x = q.front();
            q.pop();
            visited[x] = true; 
            for(auto i:adj[x]){
                if(!visited[i]){
                    if(i==n) return level;
                    q.push(i);
                }
            }
        }
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> adj[n+1];
        while(q--){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        cout<<bfs(adj,n)<<endl;
    }
	return 0;
}
