/*
Each boy has certain no of chocolates and each girl has certain no. of candies.
Pair up boys and girls such that diff. between items of (boy,girl) are minimal possible.
n(Girls) >= n(Boys)
find total minimal sum of all pairs.
*/

#include <bits/stdc++.h>
using namespace std;
#define N 5000
#define ll long long
#define INF 100000000099ll
ll dp[N][N];
int solve(int i,vector<int>& boy,int j,vector<int>& girl,int n,int m){
    if(i==n)return 0;//all boys paired
    if(j==m)return INF;//no girl left reject the case; 
    if(dp[i][j]!=-1)return dp[i][j];
    ll op1 = abs(boy[i]-girl[j]) + solve(i+1,boy,j+1,girl,n,m); //paired
    ll op2 = solve(i,boy,j+1,girl,n,m); // not paired
    dp[i][j] = min(op1,op2);
    return dp[i][j];
}

int main() {
	int n,m;
	cin>>n>>m;
	vector<int> boy(n);
	vector<int> girl(m);
	for(int i=0;i<n;i++)cin>>boy[i];
	for(int i=0;i<m;i++)cin>>girl[i];
	for(int i=0;i<N;i++)
	    for(int j=0;j<N;j++)
	        dp[i][j]=-1;
	sort(boy.begin(),boy.end());
	sort(girl.begin(),girl.end());
	cout<<solve(0,boy,0,girl,n,m);
	return 0;
}
