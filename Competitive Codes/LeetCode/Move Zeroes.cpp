class Solution {
public:
    void moveZeroes(vector<int>& a){
        int c=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=0)
                a[c++]=a[i];
        }    
        while(c<a.size()) a[c++]=0;        
    }
};