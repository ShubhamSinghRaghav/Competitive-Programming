/*
Distribute Candies

Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000). Shaky want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He want to distibute them in a way such that:
1. All students get equal number of candies.
2. All the candies which a student get must be from a single box only.
As he want to make all of them happy so he want to give as many candies as possible. Help Shaky in finding out what is the maximum number of candies which a student can get.
Input
First line contains 1<=T<=20 the number of test cases. Then T test cases follow. First line of each test case contains N and K. Next line contains N integers, ith of which is the number of candies in ith box.
Output
For each test case print the required answer in a seperate line.
Sample Input:
2
3 2 
3 1 4
4 1
3 2 3 9
Sample Output:
3
9
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll coco,ll a[],ll kids,ll n){
    for(int i=0;i<n;i++){
        kids = kids - a[i]/coco;
        if(kids<=0) return true; 
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n];
        ll ub=-1;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            ub=max(ub,a[i]);
        }
        ll lb=0,saver=0,mid;
        while(lb<=ub){
            mid = (lb+ub)/2;
            bool flag = check(mid,a,k,n); 
            if(flag){
                lb=mid+1;
                saver=mid;
            }else{
                ub=mid-1;
            }
        }
        cout<<saver<<endl;
    }
}