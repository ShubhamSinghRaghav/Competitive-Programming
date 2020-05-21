class Solution {
public:
    bool all_negative(vector<int> a){
        for(int i=0;i<a.size();i++) if( a[i] >= 0 ) return false;
        return true;
    }
    int maxSubArray(vector<int>& a) {
        if(all_negative(a)){
            return *max_element(a.begin(),a.end());
        }
        
        int prev = 0;
        int ans = 0;
        for(int i=0;i<a.size();i++){
            prev += a[i];
                if(prev > ans){
                    ans = prev;
                }
                if(prev < 0 ) prev = 0;
        }
        return ans;
        }
};