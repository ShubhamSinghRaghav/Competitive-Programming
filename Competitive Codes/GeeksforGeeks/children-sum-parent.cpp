//https://practice.geeksforgeeks.org/problems/children-sum-parent/1
int isSumProperty(Node *node){
    queue<Node*> q;
    q.push(node);
    bool flag=true;
    while(!q.empty() and flag){
        Node* temp = q.front();
        q.pop();int l=0,r=0;
        if(temp->left!=NULL){
            q.push(temp->left);
            l=temp->left->data;
        }if(temp->right!=NULL){
            q.push(temp->right);
            r=temp->right->data;
        }
        if(temp->data!=l+r and l+r>0)flag=false;
    }
    return flag;
}
