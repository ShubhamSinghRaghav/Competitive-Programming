#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[26]={0};
    a['d'-97]=1; a['f'-97]=1; a['j'-97]=0; a['k'-97]=0;
    int t;
    cin>>t;
    while(t--){ 
        
        int n;
        cin>>n;
        
        double final_sum=0;
        map<string,double> v;
        while(n--){ 
            
            double sum=0.2;
            string s;
            cin>>s;
            if(v.end()==v.find(s)){
                char hand;
                if(a[s[0]-97]) hand='L'; else hand='R';
                for(int i=1;i<s.size();i++){
                    if(a[s[i]-97]){
                        if(hand=='R')
                        sum+=0.2;
                        else sum+=0.4;
                        hand='L';
                    }
                    else{ 
                        if(hand=='L')
                        sum+=0.2;
                        else sum+=0.4;
                        hand='R';
                    }
                } 
                final_sum+=sum;
                v.insert({s,sum});
            }
            else{
                final_sum+=(v[s])/2;
            } 
        }
        cout<<final_sum*10<<"\n";
    }
    return 0;
}
