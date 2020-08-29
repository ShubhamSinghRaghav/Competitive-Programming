/*
Coin Change Problem

You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
Constraints :
1<=n<=10
1<=V<=1000
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
*/

#include<iostream>
using namespace std;

int N;
int coins(int n,int *d,int num,int **dp){
   // cout<<n<<" ";
    if(n==0) return 1;
    if(num==0 or n<0) return 0;
    if(dp[n][num]>-1) return dp[n][num];
    int first = coins(n-d[0],d,num,dp);
    int second = coins(n,d+1,num-1,dp);
    dp[n][num] = first+second;
    return first+second;
}

int countWaysToMakeChange(int den[], int numD, int value){
    N = numD+1;
    //int dp[value+1][numD+1]={-1};
    int **dp = new int*[value+1];
    for(int i=0;i<=value;i++){
        dp[i] = new int[numD+1];
        for(int j=0;j<=numD;j++) dp[i][j] = -1;
    }
    
    int ans = coins(value,den,numD,dp);
    return ans;
}


int main(){
  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << countWaysToMakeChange(denominations, numDenominations, value);

}



