class Solution {
public:
    int singleNumber(vector<int>& a) {
        int save = a[0];
        for(int i=1;i<a.size();i++){
            save = save ^ a[i];
        }
        return save;
    }
};