/*
A number is called n-factorful if it has exactly n distinct prime factors. 
Given positive integers a, b, and n, your task is to find the number of integers 
between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.
Input
Your input will consist of a single integer T followed by a newline and T test cases. 
Each test cases consists of a single line containing integers a, b, and n as described above.
Output
Output for each test case one line containing the number of n-factorful integers in [a, b].
Constraints
T < 10000

1 ≤ a ≤ b ≤ 10^6

0 ≤ n ≤ 10
Sample Input
5
1 3 1
1 10 2
1 10 3
1 100 3
1 1000 0
Sample Output
2 
2
0
8
1
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long 
#define MAX 1000000
int main(){
	vector<int> prime(MAX+1,0);
	for(int i=2;i<=MAX;i++){
		if(prime[i]==0){
			for(ll j=i;j<=MAX;j=j+i){
				prime[j]++;
			}
		}
	}
	vector<vector<int>> adj(11,vector<int>(MAX+1,0));
	for(int i=1;i<11;i++){
		for(int j=1;j<=MAX;j++){
			adj[i][j] = adj[i][j-1];
			if(prime[j]==i) adj[i][j]++;
		}
	}
	int t;
	cin>>t;
	while(t--){
		ll a,b,n;
		cin>>a>>b>>n;
         if(a==1&&n==0){
            cout<<1<<endl;
            continue;
        }
		cout<<adj[n][b] - adj[n][a-1]<<"\n";
	}
	return 0;
}