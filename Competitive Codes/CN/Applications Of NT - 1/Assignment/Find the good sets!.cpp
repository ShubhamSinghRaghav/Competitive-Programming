/*
You are given array a consisting of n distinct integers. 
A set s of numbers is called good if you can rearrange the elements in such a way 
that each element divides the next element in the order, i.e. 'si' divides 'si + 1', 
such that i < |s|, where |s| denotes size of set |s|.
Find out number of distinct good sets that you can create using the values of the array. 
You can use one value only once in a particular set; ie. a set cannot have duplicate values. 
Two sets are said to be different from each other if there exists an element in one set, 
which does not exist in the other.
As the answer could be large, print your answer modulo 10^9 + 7.

Input
First line of the input contains an integer T denoting the number of test cases. T test cases follow.
First line of each test case contains an integer n denoting number of elements in array a.
Next line contains n space separated integers denoting the elements of array a.

Output
For each test case, output a single line containing the corresponding answer.

Constraints
1 ≤ T ≤ 3

1 ≤ n ≤ 7.5 * 10^5

1 ≤ ai ≤ 7.5 * 10^5

All the elements of array a are distinct.
Example
Input
2
2
1 2
3
6 2 3
Output:
3
5
Explanation
Test case 1. There are three sets which are good {1}, {2}, {1, 2}.

Test case 2. There are five sets which are good {6}, {2}, {3}, {6 2}, {6, 3}.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n);
		for(ll i=0;i<n;i++) cin>>v[i];
		int maxa = *max_element(v.begin(),v.end());
		vector<ll> dp(maxa+1,0);
		for(auto i:v) dp[i] = 1;
		for(int i=2;i<=maxa;i++){
			if(dp[i]>0){
				for(int j=i+i;j<=maxa;j=j+i){
					if(dp[j]>0){
						dp[j]= (dp[j]+dp[i])%mod ;
					} 
				}
			}
		}
		ll c=0;
		for(auto i:dp) c=(c+i)%mod;
		cout<<c<<"\n";
	}
	return 0;
}