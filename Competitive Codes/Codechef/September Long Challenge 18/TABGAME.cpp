//@shubham_cheenu
#include<bits/stdc++.h>
using namespace std;
#define MAX 100007
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char n[1000000];char m[1000000]; long long int q;
        scanf("%s %s",m,n);
       long long int N=strlen(n),M=strlen(m);
        vector<vector<int> > a(N+2);
        a[0].push_back(0);
        for(long long int i=1;i<=M;i++){ 
            a[0].push_back(m[i-1]-'0');
        }
       long long int save=M;
        for(long long int i=1;i<=N;i++){
            a[i].push_back(n[i-1]-'0');
            for(long long int j=1;j<=M;j++){
                if(i==3) M=2;
                if(a[i][j-1]==1 && a[i-1][j]==1 )
                    a[i].push_back(0);
                else 
                    a[i].push_back(1);
            }
        }M=save;
        /*for(int i=0;i<=M;i++){
            for(int j=0;j<=N;j++){
               if(i<=2 || j<=2){
              printf("%d ",a[i][j]);  
            }
            else if(i>=j){
              printf("%d ",a[(i-j)+2][2]);  
            }
            else //if(i<j)
            {
                printf("%d ",a[2][(j-i)+2]);
            }    
            }
            printf("\n");
        }*/
       scanf("%lld",&q);
      while(q--){
            long long int i,j;
            scanf("%lld %lld",&i,&j);
            if(i<=2 || j<=2){
              printf("%d",a[i][j]);  
            }
            else if(i>=j){
              printf("%d",a[(i-j)+2][2]);  
            }
            else //if(i<j)
            {
                printf("%d",a[2][(j-i)+2]);
            }
            //printf("%d",a[x][y]);
        }
        printf("\n");
    
    }
    return 0;
}