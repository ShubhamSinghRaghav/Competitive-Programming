/*
Loot Houses
Send Feedback
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format
Line 1 : An integer N 
Line 2 : N spaced integers denoting money in each house
Output Format
 Line 1 : Maximum amount of money looted
Input Constraints
1 <= n <= 10^4
1 <= A[i] < 10^4
Sample Input :
6
5 5 10 100 10 5
Sample Output 1 :
110
*/

#include <bits/stdc++.h>
using namespace std;

int max(int a,int b){
    return a>b?a:b;
}
int getMaxMoney(int a[], int n){
    if(n==1) return a[0];
    int dp[10002]={0};
    dp[0]=a[0];
    dp[1]=max(a[1],a[0]);
    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-1],a[i]+dp[i-2]);
    }
    return dp[n-1];
}



int main(){
    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n);
}

