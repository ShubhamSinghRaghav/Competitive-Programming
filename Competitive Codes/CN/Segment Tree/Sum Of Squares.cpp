/*
Segment trees are extremely useful. In particular "Lazy Propagation" 
(i.e. see here, for example) allows one to compute sums over a range in O(lg(n)), 
and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
The sum of squares over a range with range updates of 2 types:
1) increment in a range
2) set all numbers the same in a range.
Input
There will be T (T <= 25) test cases in the input file. 
First line of the input contains two positive integers, N (N <= 100,000) and Q (Q <= 100,000). 
The next line contains N integers, each at most 1000. 
Each of the next Q lines starts with a number, which indicates the type of operation:

2 st nd -- return the sum of the squares of the numbers with indices in [st, nd]
{i.e., from st to nd inclusive} (1 <= st <= nd <= N).

1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).

0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).
Output
For each test case output the “Case <caseno>:” 
in the first line and from the second line output the sum of squares for each operation of type 2. 
Intermediate overflow will not occur with proper use of 64-bit signed integer.
Input:
2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
1 1
1
2 1 1
Output:
Case 1:
30
7
13
Case 2:
1
*/

#include<bits/stdc++.h>
using namespace std;
#define ll int
void buildTree(vector<int>& v,vector<pair<ll,ll>>& tree,int s,int e,int i){
    if(s==e){
        tree[i].first = v[s]*v[s];
        tree[i].second = v[s];
        return;
    }
    int mid = s + (e-s)/2;
    buildTree(v,tree,s,mid,2*i);
    buildTree(v,tree,mid+1,e,2*i+1);
    tree[i].first = tree[2*i].first + tree[2*i+1].first;
    tree[i].second = tree[2*i].second + tree[2*i+1].second;
}

void UpdateAddLazyTree(vector<pair<ll,ll>>& tree,vector<pair<ll,ll>>& lazy,int s,int e,int i,int left,int right,int value){
    if(s>e) return;
    if(lazy[i].first!=0 and lazy[i].second==2){
        tree[i].first += lazy[i].first*lazy[i].first*(e-s+1) + 2*lazy[i].first*tree[i].second;
        tree[i].second += lazy[i].first*(e-s+1);
        if(s!=e){
            lazy[2*i].first += lazy[i].first;
            lazy[2*i+1].first += lazy[i].first;
            lazy[2*i].second = lazy[i].second;
    	    lazy[2*i+1].second = lazy[i].second;
        }lazy[i].first = 0;
    	 //lazy[i].second = 0;
    }
    if(lazy[i].first!=0 and lazy[i].second==1){
        tree[i].first = lazy[i].first*lazy[i].first*(e-s+1);
        tree[i].second = lazy[i].first*(e-s+1);
        if(s!=e){
            lazy[2*i].first += lazy[i].first;
            lazy[2*i+1].first += lazy[i].first;
            lazy[2*i].second = lazy[i].second;
    	    lazy[2*i+1].second = lazy[i].second;
        }lazy[i].first = 0;
    	 //lazy[i].second = 0;
    }
    //completely outside
    if(s>right or e<left) return;
    //completely inside
    if(s>=left and e<=right){
        tree[i].first += value*value*(e-s+1) + 2*value*tree[i].second;
        tree[i].second += value*(e-s+1);
        if(s!=e){
            lazy[2*i].first += value;
    	    lazy[2*i+1].first += value;
            lazy[2*i].second = 2;
            lazy[2*i+1].second = 2;
        }
        return;
    }
    //partially inside
    int mid = s + (e-s)/2;
    UpdateAddLazyTree(tree,lazy,s,mid,2*i,left,right,value);
    UpdateAddLazyTree(tree,lazy,mid+1,e,2*i+1,left,right,value);
    tree[i].first = tree[2*i].first + tree[2*i+1].first;
    tree[i].second = tree[2*i].second + tree[2*i+1].second;
}

void UpdateSetLazyTree(vector<pair<ll,ll>>& tree,vector<pair<ll,ll>>& lazy,int s,int e,int i,int left,int right,int value){
    if(s>e) return;
    if(lazy[i].first!=0 and lazy[i].second==1){
    	    tree[i].first = lazy[i].first*lazy[i].first*(e-s+1);
            tree[i].second = lazy[i].first*(e-s+1);  
    	    if(s!=e){
    	        lazy[2*i].first = lazy[i].first;
    	        lazy[2*i+1].first = lazy[i].first;
                lazy[2*i].second = lazy[i].second;
    	        lazy[2*i+1].second = lazy[i].second;
    	    }lazy[i].first = 0;
    	     lazy[i].second = 2;
    }
    //completely outside
    if(s>right or e<left) return;
    //completely inside
    if(s>=left and e<=right){
        tree[i].first = value*value*(e-s+1);
    	tree[i].second = value*(e-s+1);
    	if(s!=e){
    	    lazy[2*i].first = value;
    	    lazy[2*i+1].first = value;
            lazy[2*i].second = 1;
            lazy[2*i+1].second = 1;
    	}
        return;
    }   
    //partially
    int mid = s + (e-s)/2;
    UpdateSetLazyTree(tree,lazy,s,mid,2*i,left,right,value);
    UpdateSetLazyTree(tree,lazy,mid+1,e,2*i+1,left,right,value);
    tree[i].first = tree[2*i].first + tree[2*i+1].first;
    tree[i].second = tree[2*i].second + tree[2*i+1].second;
}

int query(vector<pair<ll,ll>>& tree,vector<pair<ll,ll>>& lazy,int s,int e,int i,int left,int right){
    if(s>e) return 0;
    if(lazy[i].first!=0){
        if(lazy[i].second==1){
            tree[i].first = lazy[i].first*lazy[i].first*(e-s+1);
            tree[i].second = lazy[i].first*(e-s+1);
            if(s!=e){
                lazy[2*i].first = lazy[i].first;
                lazy[2*i+1].first = lazy[i].first;
                lazy[2*i].second = 1;
                lazy[2*i+1].second = 1;
            }
            lazy[i].first = 0;
            lazy[i].second = 2;
        }
        else{
        	tree[i].first += lazy[i].first*lazy[i].first*(e-s+1) + 2*lazy[i].first*tree[i].second;
        	tree[i].second += lazy[i].first*(e-s+1);
            if(s!=e){
                lazy[2*i].first = lazy[i].first;
                lazy[2*i+1].first = lazy[i].first;
                lazy[2*i].second = 2;
                lazy[2*i+1].second = 2;
            }lazy[i].first = 0;
            
        }
    }
    if(s>right or e<left) return 0;
    if(s>=left and e<=right) return tree[i].first;
    int mid = s + (e-s)/2;
    int a1 = query(tree,lazy,s,mid,2*i,left,right);
    int a2 = query(tree,lazy,mid+1,e,2*i+1,left,right);
    return a1 + a2;
}

int main(){
    int t;
    cin>>t;
    int jj=1;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<pair<ll,ll>> tree(4*n);
        buildTree(v,tree,0,n-1,1);
        vector<pair<ll,ll>> lazy(4*n);
        // for(int i=1;i<8;i++) {//lazy[i].first = lazy[i].second = 0;
        //     cout<<i<<"->"<<tree[i].first<<"\n";// <<" "<<tree[i].second<<"\n";
        // }
        cout<<"Case "<<jj++<<":\n";
        while(q--){
            int x;
            cin>>x;
            int left,right;
            cin>>left>>right;
            if(x<2){
                int val;
                cin>>val;
                if(x==0)
                	UpdateSetLazyTree(tree,lazy,0,n-1,1,left-1,right-1,val);
                else
                    UpdateAddLazyTree(tree,lazy,0,n-1,1,left-1,right-1,val);
            }
            else{
                cout<<query(tree,lazy,0,n-1,1,left-1,right-1)<<"\n";
            }
        }
    }
    return 0;
}/*
2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
*/