/*
N-Queen Problem

You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format :
Line 1 : Integer N
Output Format :
One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space
Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
*/
#include<bits/stdc++.h>
int board[11][11];

bool possible_case(int n,int row,int col){
    //1. upper column
    for(int i=row-1;i>-1;i--){
        if(board[i][col]==1) return false;
    }
    //2. upper left diagonal
    for(int i=row-1,j=col-1;i>-1 and j>-1;i--,j--){
        if(board[i][j]==1) return false;
    }
    //3. upper right diagonal
    for(int i=row-1,j=col+1;i>-1 and j<n;i--,j++){
        if(board[i][j]==1) return false;
    }
    return true;
}

void nQueenHelper(int n,int row){
    //base condition
    if(row==n){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cout<<board[i][j]<<" ";
        cout<<"\n";
    }
    for(int i=0;i<n;i++){
        if(possible_case(n,row,i)){
            board[row][i]=1;
            nQueenHelper(n,row+1);
            board[row][i]=0;
        }
    }
    return;
}

void placeNQueens(int n){
  //  int board[n][n];
    memset(board,0,11*11*sizeof(int));
    nQueenHelper(n,0);
}
