/*

Apoorvaa has created an elevated roof. She wants to know how much water can she save during rain.

Given n non negative integers representing the elevation map where width of every bar is 1, Find the maximum water that she can save.

Explanation for the Sample input Testcase:
Elevation Map

So the total units of water she can save is 5 units

Input Format
First line contains an integer n. Second line contains n space separated integers representing the elevation map.

Constraints
1 <= N <= 10^6

Output Format
Print a single integer containing the maximum unit of waters she can save.

Sample Input
10
0 2 1 3 0 1 2 1 2 1
Sample Output
5
Explanation
Refer to the image for explanation. Count the number of cells having water in them.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n;
	cin>>n;
	vector<ll> v(n);
	for(ll i=0;i<n;i++) cin>>v[i];
	ll left[n],right[n];
	left[0] = v[0];
	for(ll i=1;i<n;i++){
		left[i] = max(left[i-1],v[i]);
	}
	right[n-1] = v[n-1];
	for(ll i=n-2;i>=0;i--){
		right[i] = max(right[i+1],v[i]);
	}
	//for(int i=0;i<n;i++) cout<<left[i]<<" ";
	ll ans = 0;
	for(ll i=1;i<n-1;i++){
		ans += min(left[i],right[i])-v[i];
	}
	cout<<ans;
	return 0;
}