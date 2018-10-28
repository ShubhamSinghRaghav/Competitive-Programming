#include <bits/stdc++.h>
using namespace std;
#define ll long long
int pheko(int n,vector<int> v){
    ll cp;
    ll int max_value = *max_element(v.begin(),v.end());
        ll int prev=-1,res=-1;
        for(int i=0;i<n;i++){
            if(v[i]==-1) continue;
            if(prev==-1) {prev=i;continue;}
            if(v[i]-v[prev]== i-prev) {prev-i;continue;}
            if(v[i]-v[prev]>i-prev) return -2;
            cp=v[prev]+(i-prev-v[i]);
            if(cp<v[prev]) return -2;
            if(res==-1) res=cp; else res=__gcd(res,cp);    
            if(res<max_value) return -2;
        } 
    if(res==-1) return -3;
    return res;    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        ll value = pheko(n,v);
        if(value==-2) cout<<"impossible\n";
        else if(value==-3) cout<<"inf\n";
        else cout<<value<<"\n";
    }
    return 0;
}
