/*
Square Brackets

You are given:
a positive integer n,
an integer k, 1<=k<=n,
an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.
What is the number of proper bracket expressions of length 2n with opening brackets appearing in positions s1, s2,...,sk?
Illustration
Several proper bracket expressions:
[[]][[[]][]] 
[[[][]]][][[]]
An improper bracket expression:
[[[][]]][]][[]]
There is exactly one proper expression of length 8 with opening brackets in positions 2, 5 and 7.
Task
Write a program which for each data set from a sequence of several data sets:
1. reads integers n, k and an increasing sequence of k integers from input,
2. computes the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1,s2,...,sk,
3. writes the result to output.
Input
The first line of the input file contains one integer d, 1 <= d <= 10, which is the number of data sets. The data sets follow. Each data set occupies two lines of the input file. The first line contains two integers n and k separated by single space, 1 <= n <= 19, 1 <= k <= n. The second line contains an increasing sequence of k integers from the interval [1;2n] separated by single spaces.
Output
The i-th line of output should contain one integer - the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1, s2,...,sk.
Sample Input
5 
1 1 
1 
1 1 
2 
2 1 
1 
3 1 
2 
4 2 
5 7 
Sample Output
1 
0 
2 
3 
2  
*/

#include <bits/stdc++.h>
using namespace std;
int dp[50][50];
int brackets(int O,int C,int total,int n,bool visit[]){
    if(O>n or C>n) return 0;
    if(dp[O][C]) return dp[O][C];
    if(O==n and C==n){
        dp[O][C]=1;
        return 1;
    }
    int index = O+C+1;
    if(O==C or visit[index]){
        dp[O][C] = brackets(O+1,C,total,n,visit);
        return dp[O][C];
    }else if(O==n){
        dp[O][C] = brackets(O,C+1,total,n,visit);
        return dp[O][C];
    }else{
        dp[O][C] = brackets(O+1,C,total,n,visit) + brackets(O,C+1,total,n,visit);
        return dp[O][C];
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        memset(dp,0,sizeof(dp));
        bool visit[2*n+1]={false};
        while(k--){
            int y;
            cin>>y;
            visit[y] = true;
        }
        cout<<brackets(0,0,0,n,visit)<<"\n";
    }
    
    return 0;
}
