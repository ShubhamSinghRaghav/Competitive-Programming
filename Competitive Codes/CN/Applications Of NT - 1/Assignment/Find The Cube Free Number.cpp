/*
A cube free number is a number who’s none of the divisor is a cube number (A cube number is a cube of a integer like 8 (2 * 2 * 2) , 27 (3 * 3 * 3) ). 
So cube free numbers are 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18 etc (we will consider 1 as cube free). 8, 16, 24, 27, 32 etc are not cube free number. 
So the position of 1 among the cube free numbers is 1, position of 2 is 2, 3 is 3 and position of 10 is 9. Given a positive number you have to say if its a cube free number 
and if yes then tell its position among cube free numbers.
Input
First line of the test case will be the number of test case T (1 <= T <= 100000) . Then T lines follows. 
On each line you will find a integer number n (1 <= n <= 1000000).
Output
For each input line, print a line containing “Case I: ”, where I is the test case number. 
Then if it is not a cube free number then print “Not Cube Free”. 
Otherwise print its position among the cube free numbers.
Sample Input:
10
1
2
3
4
5
6
7
8
9
10
Sample Output:
Case 1: 1
Case 2: 2
Case 3: 3
Case 4: 4
Case 5: 5
Case 6: 6
Case 7: 7
Case 8: Not Cube Free
Case 9: 8
Case 10: 9
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define ll long
int main(){
	vector<bool> prime(MAX+1,true);
	for(int i=2;i<=100;i++){
		ll num = i*i*i;
		if(prime[num]){
			ll v = 1;
			while(num*v <= MAX){
				prime[num*v] = false;
				v++;
			}
		}
	}
	vector<ll> all(MAX+1);
	ll k = 1;
	for(ll i=1;i<=MAX;i++){
		if(prime[i]){
			all[i] = k;
			k++;
	    }
	}
//	for(int i=1;i<=100;i++){
//		if(prime[i]){
//			cout<<i<<" => "<<all[i]<<"\n";
//		}else{
//			cout<<"not\n";
//		}
//	}
	int t;
	cin>>t;
	k = 1;
	while(t--){
		ll n;
		cin>>n;
		cout<<"Case "<<k++<<": ";
		if(prime[n]){
			cout<<all[n];
		}else cout<<"Not Cube Free";
		cout<<endl;
	}
	return 0;
}