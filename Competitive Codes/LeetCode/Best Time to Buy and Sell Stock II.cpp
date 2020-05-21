class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len==1 or all_small(prices,len)) return 0;
        if(all_greater(prices,len)) return prices[len-1]-prices[0];
        int total_profit=0;
        int cur_sum=0;
        int least = 0;
        if(prices[0]<prices[1]) least = prices[0];
        for(int i=1;i<len;i++){
            if(prices[i-1]-prices[i] >= 0){
                least = prices[i];
                total_profit += cur_sum;
                cur_sum = 0;
            }
            else
            cur_sum = max(prices[i]-least,cur_sum);
        }
        if(cur_sum!=0) total_profit += cur_sum;
        return total_profit;
    }
private:
    bool all_small(vector<int>& a,int n){
        for(int i=0;i<n-1;i++){
            if(a[i]-a[i+1] < 0) return false;
        }
    return true;
    }
    bool all_greater(vector<int>& a,int n){
        for(int i=0;i<n-1;i++){
            if(a[i+1]-a[i] < 0) return false;
        }
        return true;
    }
};