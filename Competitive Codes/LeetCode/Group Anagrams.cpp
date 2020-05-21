class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, int> m;
        vector<vector<string>> res;
        for(string str: strs)
        {
            string t = str;
            sort(t.begin(),t.end());
            if(!m.count(t))
            {
                m[t] = res.size();
                res.push_back({});
            }
            res[m[t]].push_back(str);
            
            
        }
        
        return res;
     
        
    }
};