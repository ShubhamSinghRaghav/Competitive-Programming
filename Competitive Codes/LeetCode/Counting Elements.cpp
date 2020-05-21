class Solution {
public:
    int countElements(vector<int>& a) {
        if(a.size()==1) return 0;
        int save[1001]={0};
        for(int i=0;i<a.size();i++) save[a[i]]++;
        long long sum=0;
        for(int i=0;i<1000;i++){
            if(save[i] and save[i+1]){
                sum += save[i];
            }
        }
        return sum;
    }
};