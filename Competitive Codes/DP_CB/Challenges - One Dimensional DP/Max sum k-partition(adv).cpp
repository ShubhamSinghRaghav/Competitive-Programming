/*

Agarwal has a habit of creating Ajeeb Samasya as usual and Shubham always comes to his rescue. 
This is time he has created another samasya which is as follows. 
Read carefully! Shubham has an array of N integers and an integer K. 
He wants to create a subsequence of this array with some conditions applied. 
He builds ceil(N/K) blocks of this array with size of each block as [i∗K+1,min((i+1)∗k,N)] for 0≤i≤N/K. 
For two consecutive integers in this subsequence, he wants the integers to be of two different blocks. 
(It is not a compulsion to have one integer from each block). 
Also, lets say the indexes of any two integers of this subsequence be i and j, then he wants |i−j| != K. 
Shubham takes the sum of integers in the subsequence. 
He wonders what can be the maximum sum obtained? Help shubham in this samasya.

Input Format
First line contains two space separated integers : N and K Second line contains N space separated integers : A1, A2,…, AN

Constraints
1 ≤ N ≤ 2∗10^6

1 ≤ K ≤ N

−10^9 ≤ Ai ≤ 10^9

Output Format
print a single integer describing maximum sum that can be obtained.

Sample Input
6 5
5 4 3 2 1 -1
Sample Output
5

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main (){
	ll n,k;
	cin>>n>>k;
	vector<ll> v(n);
	ll x;
	for(ll i=0;i<n;i++){
		cin>>x;
		v[i] = x>0?x:0;
	}
	if(k==1){
		ll dp[n+1] = {0};
		dp[0] =v[1];
		dp[1] = max(v[0],v[1]);
		for(int i=2;i<n;i++){
			dp[i] = max(dp[i-1],v[i]+dp[i-2]);
		}
		cout<<dp[n-1];
	}else{
		ll f_max=0,s_max=0;
	ll pos = 0;
	ll dp[n+1]={0};
	for(int i=0;i<k;i++){
		dp[i] = v[i];
		if(v[i]>f_max){
			f_max = v[i];
			pos = i;
		}
	}
	for(int i=0;i<k;i++){
		if(i!= pos and v[i]>s_max ) s_max = v[i];
	}
	ll up_fmax = f_max;
	ll up_pos = pos;
	ll j=0;
	for(ll i=k;i<n;i++,j++){
		if(j==k){
			f_max = up_fmax;
			s_max = 0;
			pos = up_pos;
			for(ll u=i-k;u<i;u++){
				if(pos!=u and s_max<dp[u]) s_max = dp[u];	
			}
			j=0;
		}
		dp[i] = v[i] + ((i-pos)!= k?f_max:s_max);
		if(dp[i]>=up_fmax){
			up_fmax = dp[i];
			up_pos = i;
		}
	}
	cout<<up_fmax;
	}
	return 0;
}