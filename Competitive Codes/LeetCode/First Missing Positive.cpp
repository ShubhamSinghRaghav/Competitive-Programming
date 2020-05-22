class Solution {
public:
    int positive_array(vector<int>& a){
        int start_index = 0;
        for(int i=0;i<a.size();i++){
            if(a[i]<=0){
                int temp = a[i];
                a[i] = a[start_index];
                a[start_index] = temp;
                start_index++;
            }
        }
        return start_index;
    }
    int firstMissingPositive(vector<int>& nums){
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int start_index = positive_array(nums);
        vector<int> a;
        copy(nums.begin()+start_index, nums.end(), back_inserter(a));
        int n = a.size();
        for(int i=0;i<n;i++){
            if( abs(a[i]) < n+1 and a[abs(a[i])-1]>0){
                a[abs(a[i])-1] = -a[abs(a[i])-1];
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]>0) return i+1;
        }
        return n+1;
    }
};