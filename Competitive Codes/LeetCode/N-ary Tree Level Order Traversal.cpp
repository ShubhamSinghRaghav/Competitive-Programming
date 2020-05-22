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
    vector<vector<int>> res;
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL) return res;
        queue<Node* > q;
        q.push(root);
        while(!q.empty()){
            vector<int> a;
            vector<Node* > ss;
            while(!q.empty()){
                Node* save = q.front();
                q.pop();
                a.push_back(save->val);
                for(int i=0;i<save->children.size();i++) if(save->children[i])
                ss.push_back(save->children[i]);
            }
            if(a.size())
            res.push_back(a);
            for(int i=0;i<ss.size();i++) q.push(ss[i]);
        }
        return res;
    }
};//[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]