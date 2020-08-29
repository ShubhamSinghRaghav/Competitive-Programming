/*
Quick Sort Code
*/

void swap(int *a,int *b){
    int t=*a;
    *a = *b;
    *b= t;
}

int partition(int a[],int low,int high){
    int pivot = a[high];
    int i = (low-1);
    for(int j=low;j<=high;j++){
        if(a[j]<pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return (i+1);
}

void quicksort(int a[],int l,int r){
    if(l<r){
        int pi = partition(a,l,r);
        quicksort(a,l,pi-1);
        quicksort(a,pi+1,r);
    }
}

void quickSort(int a[], int size){
    quicksort(a,0,size-1);
}
