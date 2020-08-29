/*
The fight for the best number in the globe is going to finally come to an end.
The top two contenders for the best number are number 2 and number 3.
It's the final the entire world was waiting for. 
Expectorates from all across the globe came to witness the breath taking finals.
The finals began in an astonishing way.A common problem was set for both of them which included both these number.
The problem goes like this.
Given a binary string (that is a string consisting of only 0 and 1). 
They were supposed to perform two types of query on the string.
Type 0: Given two indices l and r.
Print the value of the binary string from l to r modulo 3.

Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
The problem proved to be a really tough one for both of them.
Hours passed by but neither of them could solve the problem.
So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.
Input:
The first line contains N denoting the length of the binary string .
The second line contains the N length binary string.
Third line contains the integer Q indicating the number of queries to perform.
This is followed up by Q lines where each line contains a query.
Output:
For each query of Type 0 print the value modulo 3.

Constraints:
1<= N <=10^5
1<= Q <= 10^5
0 <= l <= r < N

Sample Input
5
10010
6
0 2 4
0 2 3
1 1
0 0 4
1 1
0 0 3
Sample Output
2
1
2
1
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long
void buildTree(vector<ll>& v,vector<ll>& tree,int s,int e,int i){
    if(s==e){
        tree[i] = v[s];
        return;
    }
    int mid = s + (e-s)/2;
    buildTree(v,tree,s,mid,2*i);
    buildTree(v,tree,mid+1,e,2*i+1);
    int mod = (e-mid) % 2==0?1:2;
    tree[i] = ((tree[2*i]*mod)%3 + tree[2*i+1])%3;
}
void UpdateTree(vector<ll>& tree,int s,int e,int i,int ind){
    if(e==s){
        tree[i] = 1;
        return;
    }
    int mid = s + (e-s)/2;
    if(ind>mid){
        UpdateTree(tree,mid+1,e,2*i+1,ind);
    }else{
        UpdateTree(tree,s,mid,2*i,ind);
    }
    int mod = (e-mid) % 2==0?1:2;
    tree[i] = ((tree[2*i]*mod)%3 + tree[2*i+1])%3;
}
int query(vector<ll>& tree,int s,int e,int i,int left,int right){
    if(s>right or e<left) return 0;
    if(s>=left and e<=right){
        int md = (right-e) %2==0?1:2;
        int res = (tree[i]*md)%3;
        return res;
    }
    int mid = s + (e-s)/2;
    int a1 = query(tree,s,mid,2*i,left,right);
    int a2 = query(tree,mid+1,e,2*i+1,left,right);
    return (a1+a2)%3;
}
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> v(n);int j=0;
    for(auto i:s) v[j++] = i-'0';
    vector<ll> tree(4*n);
    buildTree(v,tree,0,n-1,1);
   // for(int i=1;i<10;i++) cout<<tree[i]<<" ";cout<<"\n";
    int q;
    cin>>q;
    while(q--){
        int x,l,r;
        cin>>x>>l;
        if(x==0){
            cin>>r;
            cout<<query(tree,0,n-1,1,l,r)<<"\n";
        }else{
            UpdateTree(tree,0,n-1,1,l);
        }
    }
    return 0;
}


