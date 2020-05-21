int cctws(Node* root,int x,int& count){
    if(!root) return 0;
    int ls = cctws(root->left ,x,count);
    int rs = cctws(root->right,x,count);
    int sum = ls+rs+ root->data;
    if(sum==x)count++;
    return sum;
}

int countSubtreesWithSumX(Node* root, int x){
	if (!root)return 0;
	// Code here
	int count=0;
	int ls=cctws(root->left,x,count);
	int rs=cctws(root->right,x,count);
	if((ls+rs+root->data)==x)count++;
	return count;
}
