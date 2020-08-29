/*
Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.
Input
The first line contains T, number of testcases.


T lines follows each containing the number N.
Output
Print T lines of output each containing the answer.
Constraints
1 <= T <= 500

0 <= N <= 50000
Sample Input:
3
2
3
4
Sample Output:
2
4
8
*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int main(){
	int t;
	cin>>t;
    vector<int> prime(50001,true);
		for(int i=2;i<=sqrt(50001);i++){
			if(prime[i]){
				for(int j=i*i;j<=50001;j=j+i){
					prime[j] = false;
				}
			}
		}
	while(t--){
		int n;
		cin>>n;
		ll ans = 1;
		for(int i=2;i<=n;i++){
			ll facts=0;
			if(prime[i]){
				ll k = i;
				for(int j=1;n/k > 0;j++){
					facts += n/k;
					k *=i;
				}
			}
			ans = (ans * ((facts + 1)%mod))%mod;
		}
		cout<<ans<<"\n";
	}
	return 0; 
}