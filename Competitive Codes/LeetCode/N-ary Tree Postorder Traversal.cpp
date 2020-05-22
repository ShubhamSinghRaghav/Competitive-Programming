/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<int> res;
public:
    void postord(Node* root){
        if(root==NULL) return;
        for(int i=0;i<root->children.size();i++) postord(root->children[i]);
         res.push_back(root->val);
    }
    vector<int> postorder(Node* root){
        postord(root);
        return res;
    }
};