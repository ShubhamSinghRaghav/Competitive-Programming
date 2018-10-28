#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int a[N][N];
int dp[N][N];
int path[N][N][2],two[N][N],five[N][N];
int main()
{
	int n;
	cin>>n;
	int zero=0,x1,y1;
	for(int i=1;i<=n;i++)
	{
	  for(int j=1;j<=n;j++)
	   {
	   	int cnt=0;
	    scanf("%d",&a[i][j]);
	   	int t=a[i][j];
	   	if(t==0){
	   		t=10,zero=1;
	   		x1=i,y1=j;
		   }
		while(t%2==0)t>>=1,cnt++;
		two[i][j]=cnt;
		cnt=0;
		while(t%5==0)t/=5,cnt++;
		five[i][j]=cnt;
		} 
    }
    for(int i=1;i<=n;i++) two[1][i]+=two[1][i-1],five[1][i]+=five[1][i-1];
    for(int i=1;i<=n;i++) two[i][1]+=two[i-1][1],five[i][1]+=five[i-1][1];
    for(int i=2;i<=n;i++) path[i][1][0]=path[i][1][1]=1,path[1][i][0]=path[1][i][1]=2;//????
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			int t1=two[i][j],t2=five[i][j];
			if(i-1)
			{
			  two[i][j]=two[i-1][j]+t1;
			  path[i][j][0]=1;//up	
			}
			if(j-1&&two[i][j]>two[i][j-1]+t1)
			{
				two[i][j]=two[i][j-1]+t1;
				path[i][j][0]=2;//right
			}
			if(i-1)
			{
			  five[i][j]=five[i-1][j]+t2;
			  path[i][j][1]=1;//up	
			}
			if(j-1&&five[i][j]>five[i][j-1]+t2)
			{
				five[i][j]=five[i][j-1]+t2;
				path[i][j][1]=2;//right
			}
		}
	}
	 int f=0;
	 if(two[n][n]>five[n][n])f=1;
	 int ret=min(two[n][n],five[n][n]);
	 if(zero&&ret>=1){//????0??? 
	 	puts("1");
		 int t1=n-x1,t2=n-y1;
		 x1--;y1--;
		 while(y1--) putchar('R');
		 while(x1--) putchar('D');
		 while(t1--) putchar('D');
		 while(t2--) putchar('R');
		 return 0;
	 }  
	 cout<<ret<<endl;
	 int x=n,y=n;
	 vector<char> ans;
	 while(x!=1||y!=1)
	 {
	 	if(path[x][y][f]==1) ans.push_back('D'),x--;
	 	else ans.push_back('R'),y--;
	 }
	 reverse(ans.begin(),ans.end());
	 for(int i=0;i<ans.size();i++)
	    putchar(ans[i]);
	return 0;
}
