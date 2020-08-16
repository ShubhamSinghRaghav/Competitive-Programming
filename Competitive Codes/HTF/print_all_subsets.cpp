#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void disp(char *a,int n){
    int j=0;
    while(n){
        int last_bit=n&1;
        if(last_bit){
            cout<<a[j];
        }
        j++;
        n=n>>1;
    }
    cout<<"\n";
}
void print_subsets(char *a){
    int n= strlen(a);
    for(int i=0;i<(1<<n);i++)
        disp(a,i);
}

int main() {
    char a[6];
    cin>>a;
    print_subsets(a);
	return 0;
}
