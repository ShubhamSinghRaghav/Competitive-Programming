class Solution {
public:
    
    int lastStoneWeight(vector<int>& stones) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        priority_queue<int> max_heap;
        for(int i=0;i<stones.size();i++){
            max_heap.push(stones[i]);
        }
        int len=stones.size();
        while(len>1){
            int a = max_heap.top(); max_heap.pop();
            int b = max_heap.top(); max_heap.pop();
            if(a==b) len=len-2;
            else{
                max_heap.push(abs(a-b));
                len=len-1;
            }
        }
        if(max_heap.empty()) return 0;
        return max_heap.top();
    }
};