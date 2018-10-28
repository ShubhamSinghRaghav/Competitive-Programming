#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n+1);
        v.push_back(0);
        for(int i=1;i<n+1;i++) cin>>v[i];
        int counter=0;
        for(int i=0;i<n;i++){
            int div=(v[i+1]-v[i])/k;
            int r=(v[i+1]-v[i])%k;
            if(div>1 || (div==1 && r!=0)){
                counter+=div;
            }
        }
        cout<<counter<<"\n";
    }
    return 0;
}
