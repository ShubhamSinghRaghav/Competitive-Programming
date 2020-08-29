/*
AlphaCode-Question

Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”

Alice: “How many different decodings?”

Bob: “Jillions!”
For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.
Input
Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits representing a valid encryption (for example, no line will begin with a 0). There will be no spaces between the digits. An input line of ‘0’ will terminate the input and should not be processed.
Output
For each input set, output the number of possible decodings for the input string. Print your answer taking modulo "10^9+7"
Sample Input:
25114
1111111111
3333333333
0
Sample Output:
6
89
1
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
bool check_zero(string s,int n){
    for(int i=0;i<n;i++) if(s[i]=='0') return true;
    return false;
}

int code_zero(string s,int n){
    int a[n+1];
    a[0]=1;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='0' and s[i]=='0') return 0;
        else if(s[i]=='0'){
            if(10*(s[i-1]-'0')>20) return 0;
            else{
                a[i]=a[i-1];
            }
        }
        else if(s[i-1]=='0' and s[i]!='0'){
            a[i]=a[i-1];
        }
        else{
            a[i] = a[i-1];
            if(s[i-2]!='0' and ((s[i-1]-'0')+10*(s[i-2]-'0')<=26)){
                a[i]=(a[i]%MOD + a[i-2]%MOD)%MOD;
            }
        }
    }
    return a[n];
}

int code(string s,int n){
    int a[n+1];
    a[0]=1;
    a[1]=1;
    for(int i=2;i<=n;i++){
        a[i] = a[i-1];
        if((s[i-1]-'0')+10*(s[i-2]-'0')<=26){
            a[i]=(a[i]%MOD + a[i-2]%MOD)%MOD;
        }
    }
    return a[n]%MOD;
}
int main(){
    string s;
    cin>>s;
    while(s!="0"){
        int n = s.size();
        bool flag = check_zero(s,n);
        if(flag) cout<<code_zero(s,n);
        else cout<<code(s,n);
        cout<<"\n";
        cin>>s;
    }
    return 0;
}
