/*
Harry Potter has n mixtures in front of him, arranged in a row. 
Each mixture has one of 100 different colors (colors have numbers from 0 to 99).
He wants to mix all these mixtures together. 
At each step, he is going to take two mixtures that stand next to each other 
and mix them together, and put the resulting mixture in their place.
When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.
Also, there will be some smoke in the process. 
The amount of smoke generated when mixing two mixtures of colors a and b is a*b.
Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.

Input
There will be a number of test cases in the input.
The first line of each test case will contain n, the number of mixtures, 1 <= n <= 100.
The second line will contain n integers between 0 and 99 - the initial colors of the mixtures.

Output
For each test case, output the minimum amount of smoke.
*/

#include <bits/stdc++.h>
using namespace std;
#define N 500
int dp[N][N];
vector<int> a;
int sum(int lb,int ub){
    int sum=0;
    for(int i=lb;i<=ub;i++){
        sum = (sum + a[i])%100;
    }
    return sum;
}

int solve(int i,int j){
    if(i>=j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans = INT_MAX;
    for(int k=i;k<=j;k++){
        int subpr = solve(i,k) + solve(k+1,j) + sum(i,k)*sum(k+1,j);
        ans = min(ans,subpr);
    }
    dp[i][j] = ans;
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
    	cin>>n;
    	for(int i=0;i<n;i++) cin>>a[i];
    	
    	for(int i=0;i<N;i++)
    	    for(int j=0;j<N;j++)
    	        dp[i][j] = -1;
    	        
    	cout<<solve(0,n-1);
    }
	return 0;
}
