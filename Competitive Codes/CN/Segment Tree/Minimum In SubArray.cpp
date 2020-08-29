/*
Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.
Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.
Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].
Contraints:
1≤N,Q,y≤10^5
1≤l,r,x≤N
Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5
Sample Output :
1
1
2
1
*/

#include<bits/stdc++.h>
using namespace std;
void buildTree(vector<int>& v,vector<int>& tree,int s,int e,int i){
    if(s==e){
        tree[i] = v[s];
        return;
    }
    int mid = s + (e-s)/2;
    buildTree(v,tree,s,mid,2*i);
    buildTree(v,tree,mid+1,e,2*i+1);
    tree[i] = min(tree[2*i],tree[2*i+1]);
}
void UpdateTree(vector<int>& v,vector<int>& tree,int s,int e,int i,int index,int value){
    if(s==e){
        tree[i] = value;
        return;
    }
    int mid = s + (e-s)/2;
    if(index > mid){
        UpdateTree(v,tree,mid+1,e,2*i+1,index,value);
    }else{
        UpdateTree(v,tree,s,mid,2*i,index,value);
    }
    tree[i] = min(tree[2*i],tree[2*i+1]);
}

int query(vector<int>& tree,int s,int e,int i,int left,int right){
    //completely outside
    if(s>right or e<left) return INT_MAX;
    //completey inside
    if(s>=left and e<=right) return tree[i];
    //Partially inside or outside
    int mid = s + (e-s)/2;
    int a1 = query(tree,s,mid,2*i,left,right);
    int a2 = query(tree,mid+1,e,2*i+1,left,right);
    return min(a1,a2);
}
int main(){
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> tree(4*n);
    buildTree(v,tree,0,n-1,1);
   // for(int i=0;i<4*n;i++) cout<<tree[i]<<" ";cout<<"\n";
    while(t--){
        char q;
        cin>>q;
        if(q=='u'){
            int x,y;
            cin>>x>>y;
            v[x-1] = y;
            UpdateTree(v,tree,0,n-1,1,x-1,y);
        }
        else{
            int left,right;
            cin>>left>>right;
            cout<<query(tree,0,n-1,1,left-1,right-1)<<"\n";
        }
    }
    return 0;
}