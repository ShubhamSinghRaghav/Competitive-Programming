class Solution {
public:
    int breaker(int n){
        int reso=0;
        while(n){
            int r =n%10;
            reso += r*r;
            n=n/10;
        }
        return reso;
    }
    bool isHappy(int n) {
        int save=1000;
        bool flag = false;
        while(save--){
            n = breaker(n);
            //cout<<x<<" ";
            if(n==1){
                flag=true;
                break;
            } 
        }
        if(flag) return true;
        return false;
    }
};