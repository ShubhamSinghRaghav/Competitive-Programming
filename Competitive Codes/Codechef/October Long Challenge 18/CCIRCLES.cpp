#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int ifdecimo(double a)
{
	int b=a;
	if((a-b)!=0)
		return 1;
	return 0;
}
struct point
{
    double x;
    double y;
    double r;
};

struct range
{
    double s;
    double e;
};

void rangeCalculation(point p1, point p2, range &bound)
{
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    double dst = sqrt(x*x + y*y);
    double r1 = p1.r;
    double r2 = p2.r;
    double m1, m2;
    if(r1 > r2)
        swap(r1, r2);
    m1 = dst - (r1 + r2);
    m2 = dst + (r1 + r2);
    if(dst == 0) // Concentric Circles
    {
        bound.s = r2 - r1;
      //  bound.e = 2*r1 + m1;
        bound.e = r1 + r2;
    }
    if(dst > r1+r2) // Outer Cirlces
    {
        bound.s = m1;
        bound.e = m2;
        if(ifdecimo(dst)) bound.s++;
    }
    if(r2 > dst + r1) // Containing Cirlces
    {
        bound.s = r2 - (dst + r1);
        bound.e = r2 + r1 + dst;
        if(ifdecimo(dst)) bound.s++;
    }
    if(dst >= r2-r1 && dst <= r1+r2) // Intersecting Circles
    {
        bound.s = 0;
        bound.e = m2;
    }
    arr[bound.s]++;
    arr[bound.e+1]--;
}

int main()
{
	
    int n, q, t; cin >> n >> q;
    point pt[n];
    t = (n*(n-1))/2; 
    range bound[t];
    for(int i = 0; i < n; ++i)
        cin >> pt[i].x >> pt[i].y >> pt[i].r;
    t = 0;
    for(int i=0;i<=1000000;i++)
	{
		arr[i]=0;
	}
	for(int i = 0; i < n; ++i)
        for(int j = i+1; j < n; ++j)
            rangeCalculation(pt[i], pt[j], bound[t++]);

	for(int i=1;i<=1000000;i++)
	{
		arr[i]=arr[i]+arr[i-1];
	}
	while(q--)
	{
		int l;
		cin>>l;
		printf("%d\n",arr[l]);
	}
//    while(q--)
//    {    long int counter=0;
//        long int k;cin>>k;
//        for(int i=0;i<t;i++){
//           if(k>=bound[i].s && k<=bound[i].e) counter++;
//        }
//     cout<<counter<<"\n";
//    }
   return 0;        
}
