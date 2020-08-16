/*

Alice is playing a weird game. Given a sequence 'a' consisting of n integers. The player can make several steps. In a single step he can choose an element of the sequence (let's denote it ak) and delete it, at that all elements equal to ak + 1 and ak - 1 also must be deleted from the sequence. That step brings ak points to the player.
Help Alice to get maximum points.(Use Fast Input Output)

Input Format
First line contains an integral value denoting size of array 'n'. Second line contains the array elements.

Constraints
1<=n<=10^5 1<=a[i]<=10^5

Output Format
Single integer denoting the maximum value that Alice could have.

Sample Input
8 
7 2 1 8 3 3 6 6
Sample Output
27

*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v;
	map<int,int> mp;
	int x;
	for(int i=0;i<n;i++){
		cin>>x; 
		mp[x]++;
		if(mp[x]==1) v.push_back(x);
	}
	sort(v.begin(),v.end(),greater<int>());
	n = v.size();
	int dp[n+1];
	dp[0] = v[0]*mp[v[0]];
	dp[1] = max(dp[0],v[1]*mp[v[1]]);
//	for(auto i:v)cout<<i<<" ";
	for(int i=2;i<n;i++){
	    if(v[i]+1 == v[i-1])
		    dp[i] = max(dp[i-1], dp[i-2] + (v[i]*mp[v[i]]));
		else    dp[i] = dp[i-1] + v[i]*mp[v[i]];
	}
	cout<<dp[n-1];
	return 0;
}