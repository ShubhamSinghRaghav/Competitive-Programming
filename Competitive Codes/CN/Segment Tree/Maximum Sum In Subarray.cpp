/*
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ).
 A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.
Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one 
query per line.
Sample Input:
3 
-1 2 3 
1
1 2
Sample Output:
2
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
struct node{
    //v1->max
    //v2->second max
    ll v1,v2;
};

void buildTree(vector<ll>& v,vector<node>& tree,ll s,ll e,ll i){
    if(s==e){
        tree[i].v1 = v[s];
        tree[i].v2 = INT_MIN;
        return;
    }
    ll mid = s + (e-s)/2;
    buildTree(v,tree,s,mid,2*i);
    buildTree(v,tree,mid+1,e,2*i+1);
    node a = tree[2*i];
    node b = tree[2*i+1];
    tree[i].v1 = max(a.v1,b.v1);
    tree[i].v2 = min(max(a.v1,b.v2),max(a.v2,b.v1));
}
node query(vector<node>& tree,ll s,ll e,ll i,ll left,ll right){
    //outside range
    if(s>right or e<left){
        node ak;
        ak.v1 = INT_MIN;
        ak.v2 = INT_MIN;
        return ak;
    }
    //inside
    if(s>=left and e<=right) return tree[i];
    //partially
    ll mid = s + (e-s)/2;
    node a = query(tree,s,mid,2*i,left,right);
    node b = query(tree,mid+1,e,2*i+1,left,right);
    node ans;
    ans.v1 = max(a.v1,b.v1);
    ans.v2 = min(max(a.v1,b.v2),max(a.v2,b.v1));
    return ans;
    //return max(a,b);
}
void UpdateTree(vector<node>& tree,ll s,ll e,ll i,ll index,ll value){
    if(s==e){
        tree[i].v1 = value;
        tree[i].v2 = INT_MIN;
        return;
    }
    ll mid = s + (e-s)/2;
    if(index > mid){
        UpdateTree(tree,mid+1,e,2*i+1,index,value);
    }else{
        UpdateTree(tree,s,mid,2*i,index,value);
    }
    node a = tree[2*i];
    node b = tree[2*i+1];
    tree[i].v1 = max(a.v1,b.v1);
    tree[i].v2 = min(max(a.v1,b.v2),max(a.v2,b.v1));
}
int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    vector<node> tree(4*n);
    buildTree(v,tree,0,n-1,1);
   // for(int i=0;i<4*n;i++) cout<<tree[i].v1<<"+"<<tree[i].v2<<"\n";
    ll q;
    cin>>q;
    while(q--){
        char x;
        cin>>x;
        if(x=='Q'){
            ll left,right;
            cin>>left>>right;
            node aa = query(tree,0,n-1,1,left-1,right-1);
            cout<<aa.v1+aa.v2<<"\n";
        }else{
            ll a,b;
            cin>>a>>b;
            v[a-1]
            //tree[a-1].v1 = b;
            UpdateTree(tree,0,n-1,1,a-1,b);
        }
    }
    return 0;
}