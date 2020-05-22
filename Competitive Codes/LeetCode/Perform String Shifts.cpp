class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = s.size();
        if(s.size()==1) return s;
        int counter=0;
        for(int i=0;i<shift.size();i++){
            if(shift[i][0]==0) counter = counter - shift[i][1];
            else{
                counter += shift[i][1];
            }
        }
        if(counter==0)return s;
        string res="";
        char save[101];
        int len = n;
        int j=0;
        if(counter>0){
            while(len>0){
                save[(j+counter)%n] = s[j];
                j++;
                len--;
            }
        }
        else{
            while(counter<0) counter = (counter+n);
            counter%=n;
            //counter*=-1;
            while(len>0){
                save[(j+counter)%n] = s[j];
                j++;
                len--;
            }
        }
        for(int i=0;i<n;i++) res+=save[i];
        return res;
    }
};