/*

In ICO School, all students have to participate regularly in SUPW. There is a different SUPW activity each day, and each activity has its own duration. The SUPW schedule for the next term has been announced, including information about the number of minutes taken by each activity.

Nikhil has been designated SUPW coordinator. His task is to assign SUPW duties to students, including himself. The school's rules say that no student can go three days in a row without any SUPW duty.

Nikhil wants to find an assignment of SUPW duty for himself that minimizes the number of minutes he spends overall on SUPW.

Input Format
A single integer N, the number of days in the future for which SUPW data is available.

N non-negative integers, where the integer in position i represents the number of minutes required for SUPW work on day i.

Constraints
N < = 1000000

Output Format
The output consists of a single non-negative integer, the minimum number of minutes that Nikhil needs to spend on SUPW duties this term

Sample Input
10
3 2 1 1 2 3 1 3 2 1
Sample Output
4
Explanation
(Explanation: 1+1+1+1)

*/
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define MAX 1000001
ll v[MAX];
ll dp[MAX];
int main(){
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>v[i];
	}
	dp[0] = v[0];
	dp[1] = v[1];
	dp[2] = v[2];
	for(ll i=3;i<n;i++){
		dp[i] = v[i] + min(dp[i-1],min(dp[i-2],dp[i-3]));
	}
	ll k = min(dp[n-1],min(dp[n-2],dp[n-3]));
	cout<<k;
	return 0;
}