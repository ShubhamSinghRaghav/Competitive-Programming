//https://practice.geeksforgeeks.org/problems/xor-of-a-given-range/1
/*Complete the function below*/
int tree[1000];
void build_tree(int arr[],int node,int a,int b){
    if(a>b)return;
    if(a==b){
        tree[node] = arr[a];
        return;
    }
    int m=(a+b)/2;
    build_tree(arr,node*2,a,m);
    build_tree(arr,node*2+1,m+1,b);
    tree[node] = tree[node*2]^tree[node*2+1];
}
int gtXor(int arr[], int n,int a,int b){
    for(int i=0;i<1000;i++)tree[i]=0;
    //int level = log(b-a)/log(2);
    //cout<<level;
    build_tree(arr,1,a,b);
    //return 0;
    //tree(0);
    return tree[1];
}

