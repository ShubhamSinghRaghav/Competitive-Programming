/*
Murder

Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Input
First line gives T, number of test cases.

2T lines follow.

First line gives you the number of stairs N

Next line gives you N numbers written on the stairs.
Output
For each test case output one line giving the final sum for each test case.
Constraints
T<=10

1<=N<=10^5

All numbers will be between 0 and 10^6.
Sample Input:
1
5
1 5 3 6 4
Sample Output:
15
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sum;
void merge(ll a[],ll l,ll mid,ll r){
    ll n1=mid-l+1;
    ll n2=r-mid;
    ll L[n1],R[n2];
    for(ll i=0;i<n1;i++) L[i] = a[l+i];
    for(ll i=0;i<n2;i++) R[i] = a[mid+i+1];
    ll i,j,k;
    i=0;j=0;k=l;
    while(i<n1 and j<n2){
        if(L[i]<R[j]){
            a[k++]=L[i];
            sum+=(L[i]*(n2-j));
            i++;
        }else{
            a[k++]=R[j];
            j++;
        }
    }
    while(i<n1){
        a[k]=L[i];k++;i++;
    }
    while(j<n2){
        a[k]=R[j];k++;j++;
    }
}

void mergeSort(ll a[],ll l,ll r){
    if(l<r){
        ll mid=(l+r)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        sum=0;
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        mergeSort(a,0,n-1);
        cout<<sum<<endl;
    }
    return 0;
}