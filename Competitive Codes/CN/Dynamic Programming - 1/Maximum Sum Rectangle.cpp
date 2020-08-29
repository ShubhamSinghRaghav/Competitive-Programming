/*
Maximum Sum Rectangle

Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
*/

#include <bits/stdc++.h>
using namespace std;

int rectangle(vector< vector<int>> a,int row,int col){
    int re = INT_MIN;
    for(int i=0;i<col;i++){
        vector<int> sum(row,0);
        for(int j=i;j<col;j++){
            for(int k=0;k<row;k++){
                sum[k] +=a[k][j];
            }
            int save = 0;
            int res = INT_MIN;
            for(int l=0;l<sum.size();l++){
                save = max(sum[l]+save,sum[l]);
                res = max(res,save);
            }
          //  cout<<res<<" ";
            re = max(res,re);
        }
    }
    return re;
}
int main(){
    int row,col;
    cin>>row>>col;
    vector< vector<int> > a(row,vector<int>(col,0));
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cin>>a[i][j];
    cout<<rectangle(a,row,col);
    return 0;
}
