//https://practice.geeksforgeeks.org/problems/print-bst-elements-in-given-range/1
void printNearNodes(Node *root, int l, int h){
    // if(root==NULL)return;
    // if(root->data>=l and root->data<=h)
    //     res.push_back(root->data);
    // printNearNodes(root->left,l,h);
    // printNearNodes(root->right,l,h);
    vector<int> res;
    queue<Node* > q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp->data>=l and temp->data<=h){
            res.push_back(temp->data);
        }
        if(temp->left!=NULL){
            q.push(temp->left);
        }if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
}
