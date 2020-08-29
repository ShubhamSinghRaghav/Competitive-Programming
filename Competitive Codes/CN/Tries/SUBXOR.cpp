/*
A straightforward question. Given an array of positive integers you have to print the number of subarrays whose XOR is less than K. Subarrays are defined as a sequence of continuous elements Ai, Ai+1, ..., Aj . XOR of a subarray is defined as Ai ^ Ai+1 ^ ... ^ Aj. Symbol ^ is Exclusive Or.
Input Format
First line contains T, the number of test cases. 
Each of the test case consists of N and K in one line, followed by N space separated integers in next line.
Output Format
For each test case, print the required answer.
Constraints:
1 ≤ T ≤ 5
1 ≤ N ≤ 10^5
1 ≤ A[i] ≤ 10^5
1 ≤ K ≤ 10^6
Sample Input
1
5 2
4 1 3 2 7   
Sample Output
3
*/
#include <bits/stdc++.h>
#define BIT_SIZE 21
#define MAX_SIZE 100005
using namespace std;
struct trieNode{
    trieNode* children[2];
    int cnt;
    trieNode(){
        cnt=0;
        children[0]=NULL;
        children[1]=NULL;
    }
};
trieNode* head;
int arr[MAX_SIZE];
void insert(int val){
    trieNode* node=head;
    trieNode* newNode;
    trieNode* temp;
    int i=0;
    for(i=BIT_SIZE-1;i>=0;i--){
        bool cb=val&(1<<i);
        if(node->children[cb]==NULL){
            newNode=new trieNode;
            newNode->cnt=1;
            node->children[cb]=newNode;
        }
        else
            (node->children[cb]->cnt)++;
        node=node->children[cb];
    }
}
long long int query(int val,int k){
    int i=BIT_SIZE-1;
    long long int ans=0;
    trieNode* node=head;
    if(head==NULL){
        return 0;
    }
    while(i>=0){
        bool p=val&(1<<i);
        bool q=k&(1<<i);
        if(q==1){
            if(node->children[p]!=NULL){
                ans+=node->children[p]->cnt;
            }
            node=node->children[1-p];
        }
        else{
            node=node->children[p];
        }
        if(node==NULL){
            break;
        }
        i--;
    }
    return ans;
}
int main()
{
    long long int ans;
    int t,n,k,mxor;
    cin>>t;
    while(t--){
        cin>>n>>k;
        head=new trieNode;
        mxor=0;
        ans=0;
        insert(mxor);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mxor=mxor^arr[i];
            ans+=query(mxor,k);
            insert(mxor);
        }
        cout<<ans<<endl;
    }
    return 0;
}