/*
Maximum Square Matrix With All Zeros

Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).
Output Format:
Line 1 : Size of maximum square sub-matrix
Sample Input :
3 3
1 1 0
1 1 1
1 1 1
Sample Output :
1
*/

#include <bits/stdc++.h>
using namespace std;
int min(int a,int b,int c){
    return a<b?(a<c?a:c):(b<c?b:c);
}
int max(int a,int b){
    return a>b?a:b;
}
int findMaxSquareWithAllZeros(int** a, int row, int col){
    int dp[row+1][col+1]={0};
    int maxa=0;
    for(int i=0;i<row;i++){
        if(a[i][0]==0) {dp[i][0]=1;maxa=1;}
        
    }
    for(int i=0;i<col;i++){
        if(a[0][i]==0) {dp[0][i]=1;maxa=1;}
    }
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(a[i][j]==0)
            dp[i][j] = min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j])+1;
            maxa=max(dp[i][j],maxa);
        }
    }
    return maxa;
}

int main()
 {
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
}

