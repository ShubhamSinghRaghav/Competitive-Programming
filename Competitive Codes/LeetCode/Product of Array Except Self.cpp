class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a){
        int n = a.size();
        vector<int> res(n);
        vector<int> left(n,1),right(n,1);
        right[0] = a[0];
        for(int i=1;i<n;i++){
            right[i] = a[i]*right[i-1];
        }
        left[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--){
            left[i] = a[i]*left[i+1];
        }
        res[0] = left[1];
        res[n-1] = right[n-2];
        for(int i=1;i<n-1;i++){
            res[i] = right[i-1]*left[i+1];
        }
        return res;
    }
};