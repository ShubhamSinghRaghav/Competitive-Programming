/*
Harshit knows by his resources that this time the winning lottery number is the 
smallest number whose sum of the digits is S and the number of digits is D. 
You have to help Harshit and print the winning lottery number.
Input Format
The Input line contains two space-separated integers: S,D
Output Format
The output contains a single integer denoting the winning lottery number
Constraints
1 <= D <= 1000
1 <= S <= 9*D
Time Limit: 1 second
Sample Input1:
9 2
Sample Output1:
18
Explanation
There are many other possible numbers like 45, 54, 90, etc with the sum of digits as 9 and number of digits as 2. 
The smallest of them is 18.
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int s,d;
    cin>>s>>d;
    vector<int> v(d);
    if(d==1) cout<<s;
    else{
        int nine = s/9;
        int left = s - nine*9;
        for(int i=0;i<nine;i++) v[i] = 9;
        for(int i=nine+1;i<d;i++) v[i] = 0;
        if(nine!=d){
            v[d-1] = 1;
            v[nine] = left-1;
        }
        for(int i=d-1;i>=0;i--)cout<<v[i];
    }
    return 0;
}