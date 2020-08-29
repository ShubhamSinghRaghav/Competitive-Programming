/*
Maximum Pair Sum
Send Feedback
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). 
There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. 
Print the sum A[i]+A[j].
Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, 
representing the number of operations. Next Q lines contain the operations.
Output
 Output the maximum sum mentioned above, in a separate line, for each Query.
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12
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