class Solution {
public:
    bool canConstruct(string s, int k){
        if(s.size()<k) return false;
        if(s.size()==k) return true;
        int a[26]={0};
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']++;
        }
        int odd=0;int even=0;
        for(int i=0;i<26;i++){
            if(a[i]){
                if(a[i]%2==0) even++;
                else odd++;
            }
        }
        if(odd==1 and even==0) return true;
        if(odd==0){
            return true;
        }
        if(k>odd-1 and even) return true;
        return false;
    }
};