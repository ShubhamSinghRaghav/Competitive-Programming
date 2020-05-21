class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int l1=S.size()-1,l2=T.size()-1;
        string s1="",s2="";
        int h=0;
        while(l1>=0){
            if(S[l1]=='#')h++;
            else{
                if(h==0) s1 += S[l1];
                h--;
                if(h<0) h=0;
            }
            l1--;
        }h=0;
        while(l2>=0){
            if(T[l2]=='#')h++;
            else{
                if(h==0) s2 += T[l2];
                h--;
                if(h<0) h=0;
            }
            l2--;
        }
        //cout<<s1<<"-"<<s2;
        if(s1==s2) return true;
        return false;
    }
};
/*

"bxj##tw"
"bxo#j##tw"

*/

