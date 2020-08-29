/*
Print Keypad Combinations Code

Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
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
#define MAX 10000007
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


void printKeypad(int num){
    string output[1000000];
    int l = keypad(num,output);
    for(int i=0;i<l;i++) cout<<output[i]<<endl;
}



int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
