/*

Given an array A, we can pick a number and delete it, then all the numbers which are 1 less or 1 more also get deleted. The number that we picked is added to the overall score. We need to maximise the score.

Input Format
The first line contains integer n that shows how many numbers are there in the sequence.
The second line contains n integers a1, a2, …, an.

Constraints
1 ≤ n ≤ 10^5 1 ≤ a[i] ≤ 10^5

Output Format
Print a single integer — the maximum number of points that can be earned.

Sample Input
9
1 2 1 3 2 2 2 2 3
Sample Output
10
Explanation
Consider the third test example. At first step we need to choose any element equal to 2. After that step our sequence looks like this [2, 2, 2, 2]. Then we do 4 steps, on each step we choose any element equals to 2. In total we earn 10 points.

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n;
	cin>>n;
	map<ll,ll> mp;
	ll x;
	ll maxa = -1;

	for(int i=0;i<n;i++){
		cin>>x;
		maxa = max(maxa,x);
		mp[x]++;
	}
	ll dp[maxa + 1]={0};
	dp[1] = mp[1];
	dp[2] = max(mp[2]*2,dp[1]);
	for(int i=2;i<=maxa;i++){
		dp[i] = max(mp[i]*i+dp[i-2],dp[i-1]); 
	}
	cout<<dp[maxa];
	return 0;
}