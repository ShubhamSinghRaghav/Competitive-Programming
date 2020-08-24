/*
It's Valentine's Day in Russia today. as we all know number of girls in Russia is more than number of boys :P hence boys have an extra advantage while choosing girl for the valentine evening. Each boy has certain number of chocolates and each girl has certain number of candies. Now you being the anchor of evening wants to pair all the boys with girls such that the sum of absolute difference between boy's chocolate and girl's candy in a pair is minimized. Ofcourse some of the girls will remain unpaired but that's okay as we are in Russia :P

Input Format
The first line consists of two integers N and M. then follow N integers in second line. Then follow M integers in third line. M >= N

Constraints
1 <= N <= 5000
1 <= M <= 5000
M >= N
1 <= chocolates <= 1000000
1 <= candies <= 1000000

Output Format
The only line which consists of required sum of absolute differences.

Sample Input
2 5
4 5
1 2 3 4 5
Sample Output
0
Explanation
we can pair boy numbered 1 with girl numbered 4 and boy numbered 2 with girl numbered 5
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
