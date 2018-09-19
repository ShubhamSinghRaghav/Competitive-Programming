#include<bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
int testcases;
cin>>testcases;
while(testcases--)
{
   int n,m,x,y;
   cin>>n>>m>>x>>y;
if(n==1&&m==1){ cout<<"Chefirnemo"<<endl;continue;}
if(n==2&&m==2){ cout<<"Chefirnemo"<<endl;continue;}
bool flag1=false;
bool flag=false;
if((n-1)>=0&&(n-1)%x==0)
  {flag=true;}
if((m-1)>=0&&(m-1)%y==0)
   {flag1=true;}
if((flag1==flag)&&flag1==true)
{
   cout<<"Chefirnemo\n";
}
else
{
    flag=false;flag1=false;
   if((n-2)>=0&&(n-2)%x==0)
  {flag=true;}
if((m-2)>=0&&(m-2)%y==0)
   {flag1=true;}

   if((flag1==flag)&&flag1==true)
{
   cout<<"Chefirnemo\n";
}
else
    cout<<"Pofik\n";

}
}
return 0;
}