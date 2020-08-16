/*

Alice is fighting with an alien to save this planet. As alien is very powerful he needs some power to overcome him. Power points are represented in the form of an array containing both positive and negative powers but the problem is he can get power equal to the product of the subarray he selects. Help him to decide maximum power he can get.

Input Format
First line contains an integral value denoting the size of array 'n' and then next line represents the array elements.

Constraints
1<=n<=100000 Product of all numbers will fit in long long int.

Output Format
Single integer denoting the maximum power.

Sample Input
8
10 1 2 -13 0 7 -18 2 
Sample Output
20

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll maxSubarrayProduct(vector<ll> arr, int n){ 
    ll max_ending_here = 1ll; 
    ll min_ending_here = 1ll; 
    ll max_so_far = 1ll; 
    ll flag = 0ll; 
    for (int i = 0; i < n; i++) { 
        if (arr[i] > 0) { 
            max_ending_here = max_ending_here * arr[i]; 
            min_ending_here = min(min_ending_here * arr[i], 1ll); 
            flag = 1ll; 
        } 
        else if (arr[i] == 0) { 
            max_ending_here = 1ll; 
            min_ending_here = 1ll; 
        } 
        else { 
            int temp = max_ending_here; 
            max_ending_here = max(min_ending_here * arr[i], 1ll); 
            min_ending_here = temp * arr[i]; 
        } 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
    } 
    if (flag == 0 && max_so_far == 1) 
        return 0; 
    return max_so_far; 
} 

int main() {
	int n;
	cin>>n;
	vector<ll> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	cout<<maxSubarrayProduct(v,n);
	return 0;
}