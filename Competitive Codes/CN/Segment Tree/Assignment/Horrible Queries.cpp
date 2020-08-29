/*
World is getting more evil and it's getting tougher to get into the Evil League of Evil.
 Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible, 
who has a PhD in horribleness (but not in Computer Science). You are given an array of N elements, which are initially all 0. 
After that you will be given C commands. They are -
0 p q v - you have to add v to all numbers in the range of p to q (inclusive), 
where p and q are two indexes of the array.

1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
Input
In the first line you'll be given T, number of test cases.

Each test case will start with N (N <= 100 000) and C (C <= 100 000). 
After that you'll be given C commands in the format as mentioned above. 
1 <= p, q <= N and 1 <= v <= 10^7.
Output
Print the answers of the queries.
Input:
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8
Output:
80  
508
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long
void UpdateTree(vector<ll>& tree,vector<ll>& lazy,ll s,ll e,ll i,ll left,ll right,ll value){
    if(s>e)return;
    if(lazy[i]!=0){
        tree[i]+= lazy[i]*(e-s+1);
        if(s!=e){
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }lazy[i] = 0;
    }
    if(s>right or e<left) return;
    if(s>=left and e<=right){
        tree[i] += value*(e-s+1);
        if(e!=s){
            lazy[2*i]   += value;
            lazy[2*i+1] += value;
        }return;
    }
    ll mid = s + (e-s)/2;
    UpdateTree(tree,lazy,s,mid,2*i,left,right,value);
    UpdateTree(tree,lazy,mid+1,e,2*i+1,left,right,value);
    tree[i]  = tree[2*i] + tree[2*i+1];
}
ll query(vector<ll>& tree,vector<ll>& lazy,ll s,ll e,ll i,ll left,ll right){
    if(lazy[i]!=0){
        tree[i]+= lazy[i]*(e-s+1);
        if(s!=e){
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }lazy[i] = 0;
    }
    if(s>right or e<left) return 0ll;
    if(s>=left and e<=right){
        if(lazy[i]!=0){
            tree[i]+=lazy[i]*(e-s+1);
            if(s!=e){
            	lazy[2*i] += lazy[i];
            	lazy[2*i+1] += lazy[i];
            }lazy[i]=0;
        }
        return tree[i];
    }
    ll mid = s + (e-s)/2;
    ll a1 = query(tree,lazy,s,mid,2*i,left,right);
    ll a2 = query(tree,lazy,mid+1,e,2*i+1,left,right);
    return a1 + a2;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        vector<ll> tree(4*n,0);
        vector<ll> lazy(4*n,0);
        while(q--){
            ll x,l,r,val;
            cin>>x>>l>>r;
            if(x==0){
                cin>>val;
                UpdateTree(tree,lazy,0,n-1,1,l-1,r-1,val);
            }else{
                cout<<query(tree,lazy,0,n-1,1,l-1,r-1)<<"\n";
            }
        }
    }
}