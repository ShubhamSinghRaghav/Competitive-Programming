#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n,m,a;
    cin>>n>>m>>a;
    long long int r1=n/a;
    if(n%a!=0) r1++;
    long long int r2=m/a;
    if(m%a!=0) r2++;
    cout<<r1*r2;
    return 0;
}
