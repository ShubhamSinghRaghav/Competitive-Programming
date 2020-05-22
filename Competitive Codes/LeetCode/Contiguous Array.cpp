class Solution {
public:
    int findMaxLength(vector<int>& a){
        int save = 0;
        map<int,int> m;
        m[0]=-1;
        int counter=0;
        for(int i=0;i<a.size();i++){
            counter += (a[i]==1?1:-1);
            if(m.find(counter)!=m.end()){
                save = max(save,i-m[counter]);
            }else{
                m[counter] = i;
            }
        }
        return save;
    }
};