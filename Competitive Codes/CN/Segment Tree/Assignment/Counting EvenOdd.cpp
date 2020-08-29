/*
Ashu and Shanu are best buddies. 
One day Shanu gives Ashu a problem to test his intelligence.
He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.
Input:
First line of the input contains the number N. Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y. 

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.
Constraints:
1<=N,Q<=10^5

1<=l<=r<=N 

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9
Note:-
indexing starts from 1.
Sample Input
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
Sample Output
2
2
4
*/

#include <bits/stdc++.h>
using namespace std;
struct node{
    int odd;
    int even;
};
void buildTree(vector<int>& v,vector<node>& tree,int s,int e,int i){
    if(s==e){
        tree[i].odd = tree[i].even = 0;
        
        if(v[s]%2==0) tree[i].even++;
        else tree[i].odd++;
        return;
    }
    int mid = s + (e-s)/2;
    buildTree(v,tree,s,mid,2*i);
    buildTree(v,tree,mid+1,e,2*i+1);
    tree[i].odd = tree[2*i].odd + tree[2*i+1].odd;
    tree[i].even = tree[2*i].even + tree[2*i+1].even;
}
node query(vector<node>& tree,int s,int e,int i,int left,int right){
    //outside
    if(s>right or e<left){
        node aka;
        aka.odd = 0;
        aka.even = 0;
        return aka;
    }
    //inside
    if(s>=left and e<=right){
        return tree[i];
    }
    int mid = s + (e-s)/2;
    node a1 = query(tree,s,mid,2*i,left,right);
    node a2 = query(tree,mid+1,e,2*i+1,left,right);
    node ans;
    ans.odd = a1.odd+a2.odd;
    ans.even = a1.even+a2.even;
    return ans;
}
void UpdateTree(vector<node>& tree,int s,int e,int i,int ind,int value){
    if(s==e){
        tree[i].odd = value%2==1?1:0;
        tree[i].even = value%2==0?1:0;
        return;
    }
    int mid = s + (e-s)/2;
    if(mid<ind){
        UpdateTree(tree,mid+1,e,2*i+1,ind,value);
    }else{
        UpdateTree(tree,s,mid,2*i,ind,value);
    }
    tree[i].odd = tree[2*i].odd + tree[2*i+1].odd;
    tree[i].even = tree[2*i].even + tree[2*i+1].even;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<node> tree(4*n);
    buildTree(v,tree,0,n-1,1);
   // for(int i=1;i<8;i++) cout<<tree[i].odd<<" "<<tree[i].even<<"\n";
    int q;
    cin>>q;
    while(q--){
        int x,left,right;
        cin>>x>>left>>right;
        if(x==0){
            v[left-1] = right;
            UpdateTree(tree,0,n-1,1,left-1,right);
        }else{
            if(x==1) cout<<query(tree,0,n-1,1,left-1,right-1).even<<"\n";
            else cout<<query(tree,0,n-1,1,left-1,right-1).odd<<"\n";
        }
    }
}