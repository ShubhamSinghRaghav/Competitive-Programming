/*

Mike’s boss gave him a string of opening and closing parenthesis asked him to find a valid parenthesis substring in it. 
He will get number of bounties equal to the length of substring he finds in return. What is the maximum amount of number of bounties he can get?

Input Format
The input file has a single line which contains a single string str that Mike's boss gave to him.

Constraints
1 <= |str| <= 100000

Output Format
Print, in a single line, the maximum amount of number of bounties Mike can get

Sample Input
(()(()()
Sample Output
4
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int n = s.size();
	int dp[n+1];
	dp[0]=0;
	stack<int> stk;
	int ans=0;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			stk.push(i);
			dp[i+1] = 0;
		}else{
			if(stk.empty()) dp[i]=0;
			else{
				int j = stk.top();
				stk.pop();

				dp[i+1] = dp[j] + (i-j+1);
				ans = max(ans,dp[i+1]);
			}
		}
	}
	cout<<ans;
	return 0;
}
