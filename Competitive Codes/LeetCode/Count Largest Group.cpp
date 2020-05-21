class Solution {
public:
    int split_sum(int n){
        int sum=0;
        while(n){
            sum   += n%10;
            n=n/10;
        }
        return sum;
    }
    int countLargestGroup(int n){
        if(n<1) return n;
        int a[10000]={0};
        for(int i=1;i<=n;i++){
            if(i<10){
                a[i]++;
                continue;
            }
            a[split_sum(i)]++;
        }
        int maxa=INT_MIN;
        for(int i=0;i<10000;i++){
            if(a[i])
            maxa = max(maxa,a[i]);
        }int counter=0;
        for(int i=0;i<10000;i++){
            if(maxa==a[i]) counter++;
        }
        return counter;
    }
};