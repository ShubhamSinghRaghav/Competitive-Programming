/*

Given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l. Create a stack of boxes which is as tall as possible. However, you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base.It is also allowable to use multiple instances of the same type of box. Your task is to write a program to find the maximum Height by any possible arrangements of the boxes.

Input Format
The first line contains an integer T denoting the no of test cases.
For every test case:
First line contains an integer N denoting the total no of boxes available.
Second line contains 3*N space separated values denoting the height, width and length of the N boxes.
Constraints
1 <= T <= 100 1 <= N <= 100 1 <= l,w,h <= 1000000

Output Format
For every test case, print the maximum height possible with the given boxes.

Sample Input
2
4
4 6 7 1 2 3 4 5 6 10 12 32
3
1 2 3 4 5 6 3 4 1
Sample Output
60
15

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll l,b,h;
};

bool check(node x,node y){
    if(x.l * x.b > y.l * y.b) return true;
    return false;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		node box[n*3];
		ll x,y,z;
		for(int i=0;i<3*n;i=i+3){
			cin>>x>>y>>z;
			box[i].l   = max(x,y);	box[i].b   = min(x,y);	box[i].h   = z;
			box[i+1].l = max(y,z);	box[i+1].b = min(y,z);	box[i+1].h = x;
			box[i+2].l = max(x,z);	box[i+2].b = min(x,z);	box[i+2].h = y;
		}
		n = 3*n;
		sort(box,box+n,check);
		//qsort(box,n,sizeof(box[0]),check);
	   // for(int i=0;i<n;i++) cout<<box[i].l<<" "<<box[i].b<<"=>"<<box[i].h<<"\n";
	    vector<ll> height(n);
	    for(int i=0;i<n;i++) height[i] = box[i].h;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(height[i] < height[j] + box[i].h and box[i].l<box[j].l and box[i].b < box[j].b){
	                height[i] = height[j] + box[i].h;
	            }
	        }
	    }
	    ll maxa = 0;
	    for(int i=0;i<n;i++) maxa = max(height[i],maxa);
	    cout<<maxa<<"\n";
	}
	return 0;
}
/*
6 5=>4
5 4=>6
6 4=>5
4 3=>1
3 2=>1
2 1=>3
3 1=>2
4 1=>3
3 1=>4
*/