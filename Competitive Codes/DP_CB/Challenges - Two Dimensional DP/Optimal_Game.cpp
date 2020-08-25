/*
Piyush and Nimit are playing a coin game. They are given n coins with values x1, x2 …. xn where 'n' is always even. They take alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes it from the row. The value of coin is received by that player. Determine the maximum value that Piyush can win with if he moves first. Both the players play optimally.

Input Format
First line contains the number of coins 'n'.
Second line contains n space separated integers where ith index denotes the value of ith coin.

Constraints
1 < N <= 30 , N is always even
0 <= Ai <= 1000000

Output Format
Print a single line with the maximum possible value that Piyush can win with.

Sample Input
4
1 2 3 4
Sample Output
6
Explanation
Piyush will pick the coin 4. Then Nimit can pick either 1 or 3. In both the cases piyush picks coin 2 and wins with a total of 6.
*/

#include <bits/stdc++.h>
using namespace std;
#define N 5000
#define ll long long
#define INF 100000000099ll
ll dp[N][N];
int solve(int i,vector<int>& coins,int j){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll op1 = coins[i] + min(solve(i+2,coins,j),solve(i+1,coins,j-1));//min bcz P2 takes max so P1 has min option left
    ll op2 = coins[j] + min(solve(i+1,coins,j-1),solve(i,coins,j-2));
    dp[i][j] = max(op1,op2);//bcz P1 has to take max to win
    return dp[i][j];
}

int main() {
	int n;
	cin>>n;
	vector<int> coins(n);
	for(int i=0;i<n;i++)cin>>coins[i];
	for(int i=0;i<N;i++)
	    for(int j=0;j<N;j++)
	        dp[i][j]=-1;
	cout<<solve(0,coins,n-1);
	return 0;
}
