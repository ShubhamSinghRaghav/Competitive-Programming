/*
Charlie and Pilots

Charlie acquired airline transport company and to stay in business he needs to lower the expenses by any means possible. There are N pilots working for his company (N is even) and N/2 plane crews needs to be made. A plane crew consists of two pilots - a captain and his assistant. A captain must be older than his assistant. Each pilot has a contract granting him two possible salaries - one as a captain and the other as an assistant. A captain's salary is larger than assistant's for the same pilot. However, it is possible that an assistant has larger salary than his captain. Write a program that will compute the minimal amount of money Charlie needs to give for the pilots' salaries if he decides to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in crews.
Input
The first line of input contains integer N, 2 ≤ N ≤ 10,000, N is even, the number of pilots working for the Charlie's company. The next N lines of input contain pilots' salaries. The lines are sorted by pilot's age, the salaries of the youngest pilot are given the first. Each of those N lines contains two integers separated by a space character, X i Y, 1 ≤ Y < X ≤ 100,000, a salary as a captain (X) and a salary as an assistant (Y).
Output
The first and only line of output should contain the minimal amount of money Charlie needs to give for the pilots' salaries. 
Sample Input
4 
5000 3000 
6000 2000 
8000 1000 
9000 6000 
Sample Output
19000 
*/

#include <bits/stdc++.h>
using namespace std;
int miner(int *cap,int *ass,int n,int i,vector<vector<int>>& dp){
    if(n==0)return 0;
    if(dp[n][i]!=-1)return dp[n][i];
    if(i==0){
        int op1 = ass[0] + miner(cap+1,ass+1,n-1,i+1,dp);
        dp[n][i] = op1;
        return op1;
    }else if(i==n){
        int op2 = cap[0] + miner(cap+1,ass+1,n-1,i-1,dp);
        dp[n][i] = op2;
        return op2;
    }else{
        int op3 = ass[0] + miner(cap+1,ass+1,n-1,i+1,dp);
        int op4 = cap[0] + miner(cap+1,ass+1,n-1,i-1,dp);
        dp[n][i] = min(op3,op4);
        return dp[n][i];
    }
}
int main(){
    int n;
    cin>>n;
    //vector<int> cap(n),ass(n);
    int cap[n],ass[n];
    for(int i=0;i<n;i++) cin>>cap[i]>>ass[i];
    vector<vector<int>> dp(n+1,vector<int>((n/2)+1,-1));
    cout<<miner(cap,ass,n,0,dp);
}
