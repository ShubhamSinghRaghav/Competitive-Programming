/*
Given an array of n integers, find subarray whose xor is maximum.
Input Format
First line contains single integer n (1<=n<=1000000).
Next line contains n space separated integers.
Output Format
Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.
Constraints
1 <= n <= 1000000
1 <= A[i] <=100000 
Sample Input
4
1 2 3 4
Sample Output
7
*/

#include<bits/stdc++.h>
using namespace std;
class trieNode{
    public:
    trieNode* left;
    trieNode* right;
};
void insert(trieNode* head,int n){
    trieNode* curr = head;
    for(int i=31;i>=0;i--){
        int b = (n>>i)&1;
        if(b==0){
            if(!curr->left){
                curr->left = new trieNode();
            }
                curr = curr->left;
        }else{
            if(!curr->right){
                curr->right = new trieNode();
            }
                curr = curr->right;
        }
    }
}
int query(trieNode* head,int n){
    int temp = n;
    int value=0;
    trieNode* curr = head;
    for(int i=31;i>=0;i--){
        int b = (temp>>i)&1;
        if(b==0){
            if(curr->right!=NULL){
                value += pow(2,i);
                curr = curr->right;
            }else{
                curr = curr->left;
            }
        }else{
            if(curr->left!=NULL){
                value += pow(2,i);
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
    }
    return value;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    trieNode* head = new trieNode();
    insert(head,0);
    int pre_xor = 0;
    int result = 0;
    for(int i=0;i<n;i++){
        pre_xor = pre_xor ^ arr[i];
        insert(head,pre_xor);
        result = max(result,query(head,pre_xor));
        //cout<<pre_xor<<"=>"<<result<<"\n";
    }
    cout<<result;
    return 0;
}
