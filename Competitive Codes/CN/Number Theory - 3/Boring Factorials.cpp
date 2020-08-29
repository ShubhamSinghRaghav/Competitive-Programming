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
typedef unsigned long long ll;
//n! % p(prime) = ?
ll power(ll a,ll p,ll mod){
	if(p==0) return 1;
	ll sa = power(a,p/2,mod);
	sa = (sa * sa)%mod;
	if(p%2==1){
		sa = (sa * a)%mod;
	}
	return sa;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,p;
		cin>>n>>p;
		if(n>=p){
			cout<<"0\n";
			continue;
		}ll fact = 1;
		for(ll i = n+1;i<p;i++){
			fact = (fact * power(i,p-2,p))%p;
		}
		cout<< (p - fact)%p<<"\n";
	}
	return 0;
}