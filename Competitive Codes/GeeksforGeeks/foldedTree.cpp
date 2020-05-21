bool isfold(node* k1,node* k2)
{
    if(k1==NULL && k2==NULL)
     return true;
    if(k1== NULL || k2==NULL)
    return false;
 return isfold(k1->left,k2->right) && isfold(k1->right,k2->left);
}

bool isFoldable(struct node *root)
{
    if(root==NULL)
    return true;
    
   if(isfold(root->left,root->right))
     return true;
     
     return false;
}
/*

bool isFoldable(struct node *root){
    int sum = 0;
    queue<node*> q;
    q.push(root);int h=0;bool flag=true;
while(flag && sum==0){
    h++;
    int len = q.size();
    while(len--){
        node *temp = q.front();
        q.pop();
        if(temp->left){
            q.push(temp->left);
            sum++;
        }if(temp->right){
            q.push(temp->right);
            sum--;
        }if(!temp->left and !temp->right) flag=false;
    }
  //  cout<<"h = "<<h<<" sum = "<<sum<<"\n";
}
    if(!sum)return true;
    return false;
}

*/
