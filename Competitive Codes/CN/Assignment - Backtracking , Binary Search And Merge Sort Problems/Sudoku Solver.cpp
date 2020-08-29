/*
Sudoku Solver

Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
Input Format :
9 Lines where ith line contains ith row elements separated by space
Output Format :
 true or false
Sample Input :
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output :
true
*/
#include<iostream>
using namespace std;

#define N 9
bool isSafeRow(int grid[][N],int row,int num){
    for(int i=0;i<N;i++){
        if(grid[row][i]==num)
            return false;
    }
    return true;
}

bool isSafeCol(int grid[][N],int col,int num){
    for(int i=0;i<N;i++){
        if(grid[i][col]==num)
            return false;
    }
    return true;
}
bool isSafeGrid(int grid[][N],int row,int col,int num){
    int rowfactor = row - (row%3);
    int colfactor = col - (col%3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
        if(grid[i+rowfactor][j+colfactor]==num)
            return false;
    }
    return true;
}

bool isSafe(int grid[][N],int row,int col,int num){
    if(isSafeRow(grid,row,num) and isSafeCol(grid,col,num) and isSafeGrid(grid,row,col,num)){
        return true;}
    return false;
}

bool full(int grid[][N],int& row,int& col){
    for(row=0;row<N;row++)
        for(col=0;col<N;col++)
            if(grid[row][col]==0) return false;
    return true;
}

bool solveSudoku(int grid[][N]){
    int row,col;
    if(full(grid,row,col)){
        return true;
    }
    
    for(int i=1;i<=9;i++){
        if(isSafe(grid,row,col,i)){
            grid[row][col] = i;
            if(solveSudoku(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

bool sudokuSolver(int grid[][9]){
    return solveSudoku(grid);
}


int main(){
  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board)){
	cout << "true";	
  }else{
	cout << "false";	
  }
}


