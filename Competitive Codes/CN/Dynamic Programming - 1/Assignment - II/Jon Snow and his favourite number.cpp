/*
Jon Snow and his favourite number

Jon Snow now has to fight with White Walkers. He has n rangers, each of which has his own strength. Also Jon Snow has his favourite number x. Each ranger can fight with a white walker only if the strength of the white walker equals his strength. He however thinks that his rangers are weak and need to improve. Jon now thinks that if he takes the bitwise XOR of strengths of some of rangers with his favourite number x, he might get soldiers of high strength. So, he decided to do the following operation k times:
Arrange all the rangers in a straight line in the order of increasing strengths.
Take the bitwise XOR of the strength of each alternate ranger with x and update it's strength.
Suppose, Jon has 5 rangers with strengths [9, 7, 11, 15, 5] and he performs the operation 1 time with x = 2. He first arranges them in the order of their strengths, [5, 7, 9, 11, 15]. Then he does the following:
The strength of first ranger is updated to 5 xor 2, i.e. 7.
The strength of second ranger remains the same, i.e. 7.
The strength of third ranger is updated to 9 xor 2, i.e. 11.
The strength of fourth ranger remains the same, i.e. 11.
The strength of fifth ranger is updated to 15 xor 2, i.e. 13.
The new strengths of the 5 rangers are [7, 7, 11, 11, 13]
Now, Jon wants to know the maximum and minimum strength of the rangers after performing the above operations k times. He wants your help for this task. Can you help him?
Input
First line consists of three integers n, k, x (1 ≤ n ≤ 10^5, 0 ≤ k ≤ 10^5, 0 ≤ x ≤ 10^3) — number of rangers Jon has, the number of times Jon will carry out the operation and Jon's favourite number respectively.

Second line consists of n integers representing the strengths of the rangers a1, a2, ..., an (0 ≤ ai ≤ 10^3).
Output
Output two integers, the maximum and the minimum strength of the rangers after performing the operation k times.
Sample Input
5 1 2
9 7 11 15 5
Sample Output
13 7
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long
#define MAX 1025
int main(){
    
    ll n,k,x;
    cin>>n>>k>>x;
    
    vector<ll> v(n);
    vector<ll> a(MAX);
    vector<ll> b(MAX);
    
    for(int i=0;i<MAX;i++) {a[i]=0;b[i]=0;}
    for(ll i=0;i<n;i++){
        cin>>v[i];
        a[v[i]]++;
    }
    
    for(ll j=0;j<k;j++){    
        ll cycle=0;
        if(j%2==0){
            for(int i=0;i<MAX;i++){
                if(a[i]){
                    if(cycle%2==0){
                        ll xr = i ^ x; 
                        ll save = ceil(a[i]*1.0/2);
                       // if(save==0) save=1;
                        b[xr] += save;
                        b[i] += a[i]-save;
                    }else{
                        ll xr = i ^ x; 
                        ll save = (a[i]/2);
                       // if(save==0) save=1;
                        b[xr] += save;
                        b[i] += a[i]-save;
                    }
                cycle += a[i];
                a[i] = 0;
              }   
              
            }
        }
        
        else{
            for(int i=0;i<MAX;i++){
            if(b[i]){
                if(cycle%2==0){
                    ll xr = i ^ x; 
                    ll save = ceil(b[i]*1.0/2);
                    //if(save==0) save++;
                    a[xr] += save;
                    a[i] += b[i]-save;
                }else{
                    ll xr = i ^ x; 
                    ll save = (b[i]/2);
                   // if(save==0) save++;
                    a[xr] += save;
                    a[i] += b[i]-save;
                }
            cycle += b[i];
            b[i] = 0;
            }     
            
            }   
        }   
    }
    if(k%2==1){
        for(int i=MAX-1;i>=0;i--){
            if(b[i]){
                cout<<i<<" ";
                break;
            }
        }
        for(int i=0;i<MAX;i++){
            if(b[i]){
                cout<<i;
                break;
            }
        }
    }else{
        for(int i=MAX-1;i>=0;i--){
            if(a[i]){
                cout<<i<<" ";
                break;
            }
        }
        for(int i=0;i<MAX;i++){
            if(a[i]){
                cout<<i;
                break;
            }
        }
    }
    return 0;
}
