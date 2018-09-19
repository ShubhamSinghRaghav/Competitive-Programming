//@author shubham_cheenu
#include <bits/stdc++.h>
using namespace std;
#define loop(x, n) for(long long int x = 0; x < n; x++)
#define dloop(x, n) for(long long int x = n; x >0 ; x--)
#define floop(x, n) for(long long int x = 4; x < n; x=x+4) 
#define MAX 1000007
int main(){
    int t;
    long long int v[MAX];
    cin>>t;
    dloop(x,t){
        long long int n,odin=0,ella=0;
        cin>>n;
        //initializing array with zero
        loop(i,MAX) v[i] = 0;
        //std::fill(v,v+MAX,0);
       // cout<<v[1000000]<<" ";
        //memset sucks!
        //memset(v,0,n);
        //loop(i,11) cout<<v[i]<<" ";
        loop(x,n){
            long long int N; cin>>N; v[N]++;
            if(N%2) odin++; else ella++;
        } 
       // cout<<v[1000]<<" ";
        //loop(i,11) cout<<v[i]<<" ";
        long long int loki=0;
        loop(i,MAX){
            if(!i) continue;
            if(v[i]>1){
                loki+=(v[i]*(v[i]+1))/2; 
                loki+=(-v[i]);
            }
        }
        floop(i,MAX){
            //if(i>3){
                loki+=(v[i]*v[i+2])+(v[i+1]*v[i+3]);
            //}
        }
        cout<<(odin*(odin+1)/2)+(ella*(ella+1)/2)-odin-ella-loki-(v[1]*v[3])<<"\n";
    }
    return 0;
}