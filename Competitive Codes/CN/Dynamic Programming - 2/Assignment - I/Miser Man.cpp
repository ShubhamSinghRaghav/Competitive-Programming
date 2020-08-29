/*
Miser Man
Send Feedback
Jack is a wise and miser man. Always tries to save his money.
One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:
1. At every city, he has to change the bus.
2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
You are to help Jack to go from A to B by spending the minimum amount of money.
N, M, K <= 100.
Input
Line 1:    N M

Line 2:    NxM Grid

Each row lists the fares the M busses to go form the current city to the next city.
Output
Single Line containing the minimum amount of fare that Jack has to give.
Sample Input
5 5
1  3  1  2  6
10 2  5  4  15
10 9  6  7  1
2  7  1  5  3
8  2  6  1  9
Sample Output
10
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    cin>>r>>c;
    vector< vector<int>> a(r,vector<int>(c));
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>a[i][j];
    vector< vector<int>> dp(r,vector<int>(c));
    for(int i=0;i<c;i++) dp[0][i] = a[0][i];
    for(int i=1;i<r;i++){
        for(int j=0;j<c;j++){
            int x,y,z;
            x=y=z=INT_MAX;
            if(j-1>=0) x = dp[i-1][j-1];
            y=dp[i-1][j];
            if(j+1<c) z = dp[i-1][j+1];
            dp[i][j] = a[i][j]+min(x,min(y,z));
        }
    }
    cout<<*min_element(dp[r-1].begin(),dp[r-1].end());
    return 0;
}
