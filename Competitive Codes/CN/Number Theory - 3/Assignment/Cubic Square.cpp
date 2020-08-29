/*
Varun is learning method of successive squaring so that 
he can calculate a^b mod m quickly. To give himself practice 
he wrote many tuples of a, b and m and went to school thinking that 
he will do it after school.
After school he found that tuples he wrote are modified by his little sister. 
His sister converted each b into base 3. Varun wrote everything in base 10.
Help Varun to do his excercise.
Input
First line of input contains a number T, number of test cases. 
Then T test cases follows each containing three numbers a (<=10^9), b and m (<=10^5) 
(a in base 10, b in base 3 and m in base 10). Number of digits in b will be less than 250.
Output
Output a number for each test case a^b mod m in base 10.
Sample Input:
2
2 10 10
3 21101 19
Sample Output:
8
3
*/

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
ll solve(ll a,string str,ll mod){
	ll ans = 1;
	for(int i=str.size()-1;i>=0;i--){
		if(str[i]=='1'){
			ans = (ans * a)%mod;
		}else if(str[i]=='2'){
			ans = ((ans * a)%mod * a)%mod;
		}
		a = ((a * a)%mod * a)%mod;
	}
	return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll a,m;
		string str;
		cin>>a;
		cin>>str;
		cin>>m;
		cout<<solve(a,str,m)<<"\n";
	}
	return 0;
}