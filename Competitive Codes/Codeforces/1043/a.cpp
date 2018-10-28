#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> v(n);
    int sum=0;
    for(int i=0;i<n;i++) cin>>v[i],sum+=v[i];
    int maxa=*max_element(v.begin(),v.end());
    while(1){
        int k=(5*maxa)-(sum);
        if(k>sum){
            cout<<maxa;break;
        }
        maxa++;
    }    
    return 0;
}
