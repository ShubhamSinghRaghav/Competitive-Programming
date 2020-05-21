#include<bits/stdc++.h>
using namespace std;
#define ll long long 
bool check(int a[],int n,ll sum,int i){
    if(i>=n) return false;
    if(sum==a[i]) return true;
    if(sum<a[i]) return false;
    return check(a,n,sum-a[i],i+1) or check(a,n,sum,i+1);
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n]={0};
        //vector<int> a(n);
        ll sum=0;
        for(int i=0;i<n;i++){ 
            cin>>a[i];
            sum+=a[i];
        }    
        if(sum%2==0){
            sum=sum/2;
            if(check(a,n,sum,0))cout<<"YES";
            else cout<<"NO";
        }else cout<<"NO";
        cout<<endl;
    }
	return 0;
}