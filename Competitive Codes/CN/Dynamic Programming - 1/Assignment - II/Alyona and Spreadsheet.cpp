/*
Alyona and Spreadsheet

During the lesson small girl Alyona works with one famous spreadsheet computer program and learns how to edit tables.
Now she has a table filled with integers. The table consists of n rows and m columns. By ai, j we will denote the integer located at the i-th row and the j-th column. We say that the table is sorted in non-decreasing order in the column j if ai, j ≤ ai + 1, j for all i from 1 to n - 1.
Teacher gave Alyona k tasks. For each of the tasks two integers l and r are given and Alyona has to answer the following question: if one keeps the rows from l to r inclusive and deletes all others, will the table be sorted in non-decreasing order in at least one column? Formally, does there exist such j that ai, j ≤ ai + 1, j for all i from l to r - 1 inclusive.
Alyona is too small to deal with this task and asks you to help!
Input
The first line of the input contains two positive integers n and m (1 ≤ n·m ≤ 100 000) — the number of rows and the number of columns in the table respectively. Note that your are given a constraint that bound the product of these two integers, i.e. the number of elements in the table.

Each of the following n lines contains m integers. The j-th integers in the i of these lines stands for ai, j (1 ≤ ai, j ≤ 109).

The next line of the input contains an integer k (1 ≤ k ≤ 100 000) — the number of task that teacher gave to Alyona.

The i-th of the next k lines contains two integers li and ri (1 ≤ li ≤ ri ≤ n).
Output
Print "Yes" to the i-th line of the output if the table consisting of rows from li to ri inclusive is sorted in non-decreasing order in at least one column. Otherwise, print "No".
Sample Input
5 4
1 2 3 5
3 1 3 2
4 5 2 3
5 5 3 2
4 4 3 4
6
1 1
2 5
4 5
3 5
1 3
1 5
Sample Output
Yes
No
Yes
Yes
Yes
No
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long
int main(){
    ll n,m;
    cin>>n>>m;
    vector < vector <ll> > a;
    vector < vector <ll> > dp;
    dp.resize(n,vector<ll>(m));
    for(ll i=0;i<n;i++){
        vector<ll> save;
        for(ll j=0;j<m;j++){
            ll x;cin>>x;
            save.push_back(x);
    	}
        a.push_back(save);
    }ll ii;
    for(ii=0;ii<m;ii++){
        dp[0][ii] = 1;
        for(ll j=1;j<n;j++){
         //   cout<<a[j][ii]<<" ";
            if(a[j][ii] >= a[j-1][ii] ) dp[j][ii] = dp[j-1][ii];
            else dp[j][ii] = j+1;
        }
    }
    // for(ll i=0;i<n;i++){
    //     for(ll j=0;j<m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<"\n";
    // }

    ll t;
    cin>>t;
    for(ll k=0;k<t;k++){
        ll x,y;
        cin>>x>>y;
        bool flag=true;
        for(ll j=0;j<m and flag;j++){
            if(dp[x-1][j]==dp[y-1][j]){
                cout<<"Yes\n";
                flag = false;
            }
        }
        if(flag) cout<<"No\n";
    }
    return 0;
}
	