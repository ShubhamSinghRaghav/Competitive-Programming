#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int a[26]={0};int countR=0,countC=0,posR=0,posC=0,fin=0;
        for(int i=0;i<s.size();i++){
                if(s[i]=='R'){countR++;posR=i;}
                else if(s[i]=='C'){ countC++;posC=i;}
        }
        //if(posR==0 && countR==1 && countC==1 && posC!=1){
        	    
                int digit=100,res=26,rem,rema;
                res = digit/res;
                rem = digit%26;
                while(res>0){
                	rema = (res%10);
                	cout<<(char)(rema+65);
                	res = res/10;
				}
				cout<<(char)(rem+65);
                
        //}
//		else{
//        	long int counter=0;
//          for(long int i=0;i<s.size();i++){
//          		if(s[i]>='A' && s[i]<='Z')
//				  {
//				  	
//				    counter++;
//				  }  
//		  }
//        }
        
    }
    return 0;
}
