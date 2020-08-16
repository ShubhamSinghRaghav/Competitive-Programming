#include <iostream>
using namespace std;
//O(logN) Power exponentiation using Divide and Conquer
int Power(int a,int n){
    if(n==0) return 1;
    int sa = pow2(a,n/2);
    sa*=sa;
    if(n&1) sa*=a;
    return sa;
}
//O(logN) Power exponentiation using bitwise operator
int power(int a,int n){
    int last_bit=0;
    int ans=1;
    while(n){
        last_bit = n&1;
        if(last_bit){
            ans = ans*a;
        }
        a=a*a;
        n=n>>1;
    }
    return ans;
}
int main() {
    int a,n;
    cin>>a>>n;
    cout<<power(a,n);
	return 0;
}
