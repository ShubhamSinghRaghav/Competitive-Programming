/*
The fibonacci sequence is defined by the following relation:
 F(0) = 0
 F(1) = 1
 F(N) = F(N - 1) + F(N - 2), N >= 2
Your task is very simple. Given two non-negative integers N and M (N <= M), 
you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.
Input Format :
Two non-negative integers N and M. (N <= M)
Output Format :
A single line containing the answer for the task.
Sample Input :
10 
19
Sample Output :
10857
*/


#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef unsigned long long ll;
long long int ff;
void multiply(ll A[2][2],ll M[2][2]){
	ll f = (A[0][0]*M[0][0]%mod + A[0][1]*M[1][0]%mod)%mod;
	ll s = (A[0][0]*M[0][1]%mod + A[0][1]*M[1][1]%mod)%mod;
	ll t = (A[1][0]*M[0][0]%mod + A[1][1]*M[1][0]%mod)%mod;
	ll l = (A[1][0]*M[0][1]%mod + A[1][1]*M[1][1]%mod)%mod;
	A[0][0] = f;
	A[0][1] = s;
	A[1][0] = t;
	A[1][1] = l;
}
void power(ll A[2][2],ll n){
	if(n==0 or n==1) return;
	power(A,n/2);
	multiply(A,A);
	if(n%2==1){
		ll M[2][2] = {{1,1},{1,0}};
		multiply(A,M);
	}
	
}
ll fib(ll n){
	ll A[2][2] = {{1,1},{1,0}};
	if(n==0) return 0;
	power(A,n-1);
	return A[0][0];
}
unsigned long long fiboSum(unsigned long long m,unsigned long long n){
	return (fib(n + 2)%mod - fib(m + 1)%mod+mod)%mod;
}

