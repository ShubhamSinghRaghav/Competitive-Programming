#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    if(n==2){
        cout<<"1 2\n";
        cout<<"2 1\n";
    }
    if(n==3){
        cout<<"2 3 1\n";
        cout<<"1 2 3\n";
    }
    if(n==4){
        //while(1){}
        cout<<"2 1 4 3\n";
        cout<<"4 1 2 3\n";
       }
    if(n>4 && n<8){
        cout<<"2 3 1 5 ";
        for(int i=6;i<=n;i++) cout<<i<<" ";
        cout<<"4\n";
        cout<<n<<" ";
        for(int i=1;i<n;i++) cout<<i<<" ";
        cout<<"\n";
    }
    if(n==13){
        cout<<"2 3 4 5 6 1 8 9 10 11 12 13 7\n";
        cout<<"13 1 2 3 4 5 6 7 8 9 10 11 12\n";
    }
    if(n==14){
       cout<<"2 3 4 5 6 7 1 9 10 11 12 13 14 8\n";
       cout<<"14 1 2 3 4 5 6 7 8 9 10 11 12 13\n";
    }
    if(n==15){
       cout<<"2 3 4 5 6 7 1 9 10 11 12 13 14 15 8\n";
       cout<<"15 1 2 3 4 5 6 7 8 9 10 11 12 13 14\n";
    }
    if(n==16){
       cout<<"2 3 4 5 6 7 8 1 10 11 12 13 14 15 16 9\n";
       cout<<"16 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15\n";
    }
    if(n==17){
       cout<<"2 3 4 5 6 7 8 1 10 11 12 13 14 15 16 17 9\n";
       cout<<"17 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16\n";
    }
//     if(n>7){
        
//         cout<<n<<" ";
//         for(int i=1;i<n;i++) cout<<i<<" ";
//         cout<<"\n";
//     }
    return 0;
}