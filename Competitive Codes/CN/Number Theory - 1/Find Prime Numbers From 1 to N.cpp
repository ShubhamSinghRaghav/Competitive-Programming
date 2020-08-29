/*
Given a number N, find number of primes in the range [1,N].
Input:
The only line of input consists of a number N
Output:
Print the number of primes in the range [1,N].`
Constraints:
1≤N≤1000000
Sample Input :
3 
Sample Output -
2
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long
//seive

int main(){
	ll n;
    cin>>n;
    vector<bool> prime(n+1,true);
    for(ll i=2;i<=sqrt(n);i++){
        if(prime[i]){
            for(ll j=i*i;j<=n;j=j+i){
                prime[j] = false;
            }
        }
    }
    ll c=0;
    for(ll i=2;i<=n;i++){
        if(prime[i])c++;
    }
    cout<<c;
	return 0;
}