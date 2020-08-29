/*
Inversion Count
Send Feedback
Let A[0 ... n-1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A (where i and j are indexes of A). Given an integer array A, your task is to find the number of inversions in A.
Input format :
Line 1 : n, array size
Line 2 : Array elements (separated by space).
Output format :
Count of inversions
Constraints :
1 <= n <= 10^5
1 <= A[i] <= 10^9
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Sample Input 2 :
5
2 5 1 3 4
Sample Output 1 :
4
*/

#include <iostream>
using namespace std;

#include "solution.h"

int main()
{
    int n;
    cin >> n;

    long long* arr = new long long[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << getInversions(arr, n);

    delete arr;
}

#define ll long long
ll inversions=0;

void merge(int a[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+i+1];
    
    int i,j,k;
    i=0;j=0;k=l;
    while(i<n1 and j<n2){
        if(L[i]<=R[j]){
            a[k++]=L[i];
            i++;
        }
        else{
            inversions+=(n1-i);
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


void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 


long long solve(int a[], int n){
    mergeSort(a,0,n-1);
    return inversions;
}


