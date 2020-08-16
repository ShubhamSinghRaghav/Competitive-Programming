/*

Tughlaq introduces a strange monetary system. He introduces copper coins and each coin has a number written on it. 
A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. 
A coin can also be sold for gold. One can get as much grams of gold as the number written on the coin. 
You have one copper coin. What is the maximum weight of gold one can get from it?

Input Format
The input file contains a single integer n, the number on the coin.

Constraints
0 <= n <= 1 000 000 000

Output Format
Print the maximum weight of gold you can get.

Sample Input
12
Sample Output
13

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long int MAX = 1e9 + 7;
//vector<ll> dp;
ll solve(unordered_map<ll,ll>& dp,ll n){
	if(n<=1) return n;
	if(dp.find(n)!=dp.end()) return dp[n];
    ll op1 = -1; 
	op1 = solve(dp,n/2) + solve(dp,n/3) + solve(dp,n/4);
	ll ans = max(n,op1);
	dp.insert({n,ans});
	return dp[n];
}
int main(){
	ll n;
	cin>>n;
	unordered_map<ll,ll> dp;
	cout<<solve(dp,n);
	return 0;
}
