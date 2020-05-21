//https://practice.geeksforgeeks.org/problems/max-level-sum-in-binary-tree/1
int maxLevelSum(Node * root){
   queue<Node* > q;
   int l=0,r=0;
   q.push(root);int maxa=INT_MIN;
   while(!q.empty()){
       int len = q.size();
       int sum=0;
       while(len--){
           l=0;r=0;
           Node* temp = q.front();
           q.pop();
           if(temp->left!=NULL){
               q.push(temp->left);
               l=temp->left->data;
           }if(temp->right!=NULL){
               q.push(temp->right);
               r=temp->right->data;
           }
           sum+=l+r;
       }
       maxa=max(sum,maxa);
   }
   return maxa;
}

