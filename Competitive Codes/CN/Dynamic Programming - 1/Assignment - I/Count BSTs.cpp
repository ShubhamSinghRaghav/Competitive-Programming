/*
Count BSTs

Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.
Input Format :
Integer n 
Output Format :
Count of BSTs
Contraints :
1<= N <=1000
Sample Input 1:
8
Sample Output 1:
1430
Sample Input 2:
3
Sample Output 2:
5
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int countBST(int n){
    ll dp[n+1];
    for(int i=0;i<=n;i++) dp[i]=1;
    for(int i=2;i<=n;i++){
        int save=0;
        for(int j=0;j<i;j++){
            save =(save%MOD +  (dp[j]*dp[i-(j+1)])%MOD)%MOD;  
        }
        dp[i]=(save)%MOD;
    }
    return dp[n];
}

int main()
{
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}


