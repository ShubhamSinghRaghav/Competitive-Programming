class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int res=0;
        set<int> s;
        for(auto j:a) s.insert(j);
        for(auto i:s){
            if(s.find(i-1)==s.end()){
                //cout<<i<<" ";
                int cur = 1;
                int save = i;
                while(s.find(save+1)!=s.end()){
                    cur++;
                    save +=1;
                   // cout<<cur<<" ";
                }
                res = max(res,cur);
            }
        }
       return res;
    }
};