/*
Return Keypad Code

Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/
#include <iostream>
#include <string>
using namespace std;

string key[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int count=0; 
int keypad(int n, string output[]){
    if(n==0){
        output[0]="";
        return 1;
    }
    int r = n%10;
    int len = keypad(n/10,output);
    //int ss= output.size();
    string save[len];
    for(int i=0;i<len;i++) save[i]=output[i];
    for(int i=0;i<len;i++){
        //string save = output[i];
        int pos = key[r].size();
        for(int j=0;j<pos;j++){
            output[j+(i*pos)]=save[i]+key[r][j];
        }
    }
    return key[r].size()*len;
}



int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}



