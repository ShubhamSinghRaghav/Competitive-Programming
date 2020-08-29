/*
Number Of Balanced BTs

Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 40
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/

#define MOD 1000000007
#define ll long long int
int balancedBTs(int h){
    ll D[h+1]={0};
    D[0]=1;
    D[1]=1;
    for(int i=2;i<=h;i++){
        D[i] = ((D[i-1]*D[i-1])%MOD + (2*D[i-1]*D[i-2])%MOD)%MOD ;
    }
    return D[h];
}
