//https://practice.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1
void summer(Node* root,int index,map<int,int> &v){
    if(root==NULL) return;
    v[index]+=root->data;
    summer(root->left,index+1,v);
    summer(root->right,index,v);
    //return v;
}
void diagonalSum(Node* root){
    map<int,int> v;
    summer(root,0,v);
    map<int,int>::iterator i;
    for(i=v.begin();i!=v.end();i++){
        cout<<i->second<<" ";
    }
    cout<<"\n";
}
