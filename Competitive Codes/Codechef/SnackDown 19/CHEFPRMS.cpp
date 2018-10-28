#include <bits/stdc++.h>
using namespace std;

int checkSemiprime(int num) 
{
    if(!((double)(sqrt(num))-(int)sqrt(num))) return 0;
    int cnt = 0; 
  
    for (int i = 2; cnt < 2 && i * i <= num; ++i) 
        while (num % i == 0) 
            num /= i, ++cnt; 
    if (num > 1) 
        ++cnt; 
    return cnt == 2; 
} 

int main()
{
//	int a[]={6, 10, 14, 15, 21, 22, 26, 33, 34, 35, 38, 39, 46, 51, 55, 57, 58, 62, 65, 69, 74, 77, 82, 85, 86, 87, 91, 93, 94, 95, 106, 111, 115, 118, 119, 122, 123, 129, 133, 134, 141, 142, 143, 145, 146, 155, 158, 159, 161, 166, 177, 178, 183, 185, 187, 194};
    long int T;
    cin>>T;
    for (long i=0; i<T; i++)
    {
        int N;
        cin>>N;
        bool flag=false;
       for(int j = 2; j <= N; ++j)
    {
        if (checkSemiprime(j) && checkSemiprime(N - j))
        {
            	cout << "YES "<<"\n";
                flag = true;
                break;
        }
    }
    if (!flag)  cout <<"NO"<<"\n";
    }
    
    return 0; 
    }
