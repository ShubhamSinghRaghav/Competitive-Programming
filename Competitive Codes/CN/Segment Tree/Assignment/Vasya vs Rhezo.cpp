/*
Vasya vs Rhezo
Send Feedback
Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. 
Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, 
and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. 
Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. 
If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. 
If still there is more than 1 warrior with same maximum A value and same minimum B value, 
she chooses the one with lower index in line.
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
Input:
First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.
Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should choose.
Constraints:
1≤ N,Q ≤10^6
1≤ Ai,Bi ≤10^9
1≤Li≤Ri
Sample Input
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5
Sample Output
2
2
4
5
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000000000
struct node{
    ll war;
    ll maxa;
    ll minb;
    //ll pos;
};
struct head{
    ll a;
    ll b;
};
void buildTree(vector<head>& v,vector<node>& tree,ll s,ll e,ll i){
    if(s==e){
        tree[i].war  = s+1;
        tree[i].maxa = v[s].a;
        tree[i].minb =  v[s].b;
        //tree[i].pos = s+1;
        return;
    }
    ll mid = s + (e-s)/2;
    buildTree(v,tree,s,mid,2*i);
    buildTree(v,tree,mid+1,e,2*i+1);
    node left = tree[2*i];
    node right = tree[2*i+1];
    if(left.maxa > right.maxa){
        tree[i].maxa = left.maxa;
        tree[i].minb = min(left.minb,right.minb);
        tree[i].war = left.war;
    }else if(left.maxa == right.maxa){
        tree[i].maxa = left.maxa;
        if(left.minb<right.minb){
            tree[i].minb = left.minb;
            tree[i].war = left.war;
        }else if(left.minb==right.minb){
            tree[i].minb = left.minb;
            if(left.war < right.war){
                tree[i].war = left.war;
            }else{
                tree[i].war = right.war;
            }
        }else{
            tree[i].minb = right.minb;
            tree[i].war = right.war;
        }
    }else{
        tree[i].maxa = right.maxa;
        tree[i].minb = min(left.minb,right.minb);
        tree[i].war = right.war;
    }
}
node query(vector<node>& tree,int s,int e,int i,int le,int ri){
    //outside
    if(s>ri or e<le){
        node aka;
        aka.war = -1;
        aka.maxa = -1;
        aka.minb = MAX;
        return aka;
    }
    //inside
    if(s>=le and e<=ri){
        return tree[i];
    }
    ll mid = s + (e-s)/2;
    node left = query(tree,s,mid,2*i,le,ri);
    node right = query(tree,mid+1,e,2*i+1,le,ri);
    node ans;
    if(left.maxa > right.maxa){
        ans.maxa = left.maxa;
        ans.minb = min(left.minb,right.minb);
        ans.war = left.war;
    }else if(left.maxa == right.maxa){
        ans.maxa = left.maxa;
        if(left.minb<right.minb){
            ans.minb = left.minb;
            ans.war = left.war;
        }else if(left.minb==right.minb){
            ans.minb = left.minb;
            if(left.war < right.war){
                ans.war = left.war;
            }else{
                ans.war = right.war;
            }
        }else{
            ans.minb = right.minb;
            ans.war = right.war;
        }
    }else{
        ans.maxa = right.maxa;
        ans.minb = min(left.minb,right.minb);
        ans.war = right.war;
    }
    return ans;
}
int main(){
    ll n,q;
    cin>>n;
    vector<head> v(n);
    for(int i=0;i<n;i++) cin>>v[i].a;
    for(int i=0;i<n;i++) cin>>v[i].b;
    vector<node> tree(4*n);
    buildTree(v,tree,0,n-1,1);
    //for(int i=1;i<4*n;i++) cout<<tree[i].war<<" "<<tree[i].maxa<<" "<<tree[i].minb<<"\n";
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<query(tree,0,n-1,1,l-1,r-1).war<<"\n";
    }
}






