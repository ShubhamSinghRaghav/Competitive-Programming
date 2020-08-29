/*
There are only three phases in Swaps life: Sleep, Play and Study. 
Also, there are two types of emotions Swaps experiences: Happy and Sad. 
Each phase of his life brings either kind of emotions.
The sleep and the play phase makes Swaps happy whereas the study phase makes him sad.
Quite obvious, isn't it? But we know that life isn't that great, one cannot be happy all the time.
Swaps, being a very sensitive guy, doesn't like to mix his emotions in a particular day. 
So each day, he is in exactly one of the three phases.
Given N which denotes the number of days and K which denotes 
the exact number of days Swaps needs to be happy out of these N days, 
can you tell him in how many ways can he achieve this? 
Since the output value can be very large, take modulo with 1000000007(10^9+7)
Input:
The first line of the input contains T, denoting the number of test cases.

The next T lines contain two space-separated integers N and K.
Output:
For each test-case, output a single integer, the number of ways modulo 1000000007(10^9+7).
Constraints:
1 ≤ T ≤ 10^5
1 ≤ N ≤ 10^6
1 ≤ K ≤ 10^6
K ≤ N
Sample Input :
3
1 1
2 1
3 2
Sample Output:
2
4
12
Explanation
In the first test case, he needs to be happy on Day 1. Hence, answer is 2 (He can either play or sleep).

In the second test case, he can be happy either on Day 1 or Day 2. So number of ways = 4.
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
#define MAX 1000001
ll power(ll a,ll p){
	if(p==0) return 1;
	ll ans = power(a,p/2);
	ans = (ans * ans)%mod;
	if(p%2==1){
		ans = (ans * a)%mod;
	}
	return ans;
}
int main(){
	int t;
	cin>>t;
	vector<ll> fact(MAX);
	fact[0]=1;
	for(int i=1;i<MAX;i++){
		fact[i] = (fact[i-1]*i)%mod;
	}
	while(t--){
		ll n,k;
		cin>>n>>k;
		ll reso = power(2,k);
		reso = (reso * fact[n])%mod;
		reso = (reso * power(fact[n-k],mod-2))%mod;
		reso = (reso * power(fact[k],mod-2))%mod;
		cout<<reso<<"\n";
	}
	return 0;
}