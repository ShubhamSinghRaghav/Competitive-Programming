/*
Gengar has got an integer N. Now using his ghostly powers, 
he can create the permutation from 1 to N of this given number.
Since, he's a special kind of Poke'mon, 
so he thinks he deserves special permutations. 
He wants to find the total number of special permutations of length N, consisting of the integers from 1 to N
.

A permutation is called special if it satisfies following condition:
If Ap & Aq == Ap, then p < q, where p and q are two distinct indices of permutation 
and A is the permutation itself. "&" denotes the bitwise and operation.
Help Gengar in finding the number of such permutations.
Input format:
The only line of input will consist of a single integer N denoting the length of the permutation.
Output format:
Output the total number of special permutations of length N
.

Constraints:
1 ≤ N ≤ 20

SAMPLE INPUT
4

SAMPLE OUTPUT
8

Explanation
All the special permutations of length 4 are: 1 2 3 4

1 2 4 3

1 4 2 3

2 1 3 4

2 1 4 3

2 4 1 3

4 1 2 3

4 2 1 3
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long
vector<ll> masker[21];
vector<bool> visited(1<<21);
vector<ll> dp(1<<21);

ll solve(int mask,int n){
    if(mask == (1<<(n+1))-2) return 1;
    if(visited[mask]) return dp[mask];
    visited[mask] = true;
    ll &ret = dp[mask];
    int x;
    for(int i=1;i<=n;i++){
        if(!(mask&(1<<i))){
            bool flag = true;
            for(int j=0;j<masker[i].size();j++){
                x = masker[i][j];
                if(!(mask & (1<<x))){
                    flag = false;
                }
            }
            if(flag){
                ret += solve(mask | (1<<i) , n);
            }
        }
    }
    return ret;
} 

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=20;i++){
        //cout<<i<<" ";
        for(int j=i-1;j>=1;j--){
            if((i&j)==j){
       //         cout<<j<<" ";
                masker[i].push_back(j);
            }
        }
     //   cout<<"\n";
    }
    long ans = solve(0,n);
    cout<<ans;
    return 0;
}






