/*
Boredom

Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" . In this game there are N integers on a board. In one move, he can pick any integer x from the board and then all the integers with value x+1 or x-1 gets destroyed .This move will give him x points.
He plays the game until the board becomes empty . But as he want show this game to his friend Steven, he wants to learn techniques to maximise the points to show off . Can you help Gary in finding out the maximum points he receive grab from the game ?
Input Format :
Line 1 : Integer N 
Line 2 : A list of N integers
Output Format :
Maximum points Gary can recieve from the Game setup
Constraints :
1<=N<=10^5
1<=A[i]<=1000
Sample Input :
2
1 2
Sample Output :
2
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int solve(int n,vector<int>A){
    int hash[1001] = {0};
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        hash[A[i]]++;
    }
    
    for(int i=1;i<1001;i++){
        if(hash[i]){
            v.push_back(make_pair(i,i*hash[i]));
        }
    }
    
    ll dp[n+1]={0};
    dp[0] = v[0].second;
    if(v[0].first==v[1].first-1)
    dp[1] = max(v[0].second,v[1].second);
    else
        dp[1] = dp[0] + v[1].second;
    
    for(int i=2;i<v.size();i++){
        if(v[i].first == v[i-1].first+1)
        dp[i] = max(dp[i-1],v[i].second + dp[i-2]);
        else{
            dp[i] = dp[i-1] + v[i].second;
        }
    }
    return dp[v.size()-1];
}

int n;
vector<int>A;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	cout<<solve(n,A)<<endl;
}
