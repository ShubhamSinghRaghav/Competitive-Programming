/*

Given an array of integers where each element represents the max number of steps that can be made forward from that element. Print the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Input Format
n, size of array Ai, array elements

Constraints
1<=n<=5000 1<=Ai<=10^5

Output Format
Number of minimum jumps

Sample Input
11
1 3 5 8 9 2 6 7 6 8 9
Sample Output
3
Explanation
3 (1-> 3 -> 8 ->9)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)	cin>>v[i];
	vector<int> dp(n+1,0);
	dp[0]=0;
	for(int i=1;i<n;i++){
		int ans  = INT_MAX;
		for(int j=i-1;j>=0;j--){
			if(i-j<=v[j])
			ans = min(ans,1 + dp[j]);
		}
		dp[i] = ans;
	}
	cout<<dp[n-1];
	//for(auto i:dp) cout<<i<<" ";
	return 0;
}