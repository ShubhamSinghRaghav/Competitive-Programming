/*
Given two strings S and T, write a function to find if T is present as a substring inside S or not. 
If yes, return the starting index otherwise return -1.

Input format :
Line 1 : String S
Line 2 : String T

Sample Input 1:
WelcomeBack
come 
Sample Output 1:
3
Sample Input 2:
WelcomeBack
code
Sample Output 2:
-1
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> preffix(char pattern[],int n){
    vector<int> lps(n);
    lps[0] = 0;
    int i=1;
    int j=0;
    while(i<n){
        if(pattern[i]==pattern[j]){
            lps[i] = j+1;
            i++;
            j++;
        }else{
            if(j!=0){
                j = lps[j-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int findString(char text[], char pattern[]){
    int n=0,tlen=0;
    while(pattern[n++]);
    n--;
    vector<int> lps = preffix(pattern,n);
    while(text[tlen++]); 
    int i,j;
    i=0;
    j=0;tlen--;
    //cout<<n<<" "<<tlen<<" ";
    while(i<tlen and j<n){
        if(text[i]==pattern[j]){
            if(j==n-1){
                return i-n+1;
            }
            i++;
            j++;
        }else{
            if(j==0) i++;
            else{
                j = lps[j-1];
            }
        }
    }
    return -1;
}
