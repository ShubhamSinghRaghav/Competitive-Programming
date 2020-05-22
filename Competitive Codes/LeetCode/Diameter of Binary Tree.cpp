/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans;
    int diameterOfBinaryTree(TreeNode* root) {
        ans=1;
        height(root);
        return ans-1;
    }
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int L = height(root->left);
        int R = height(root->right);
        ans = max(ans,L+R+1);
        return max(L,R)+1;
    }
};