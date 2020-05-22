class Solution {
public:
    int maxArea(vector<int>& height){
        int lb = 0, ub = height.size()-1;
        int max_area = 0;
        while(lb < ub){
            max_area = max(max_area,min(height[ub],height[lb])*(ub-lb));
           // cout<<max_area<<" ";
            if(height[ub]>height[lb]) lb++;
            else ub--;
        }
        return max_area;
    }
};
auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();