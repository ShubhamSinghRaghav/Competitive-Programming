class Solution {
public:
    bool all_neg(vector<int> a,int n){
        for(int i=0;i<n;i++) if(a[i]>0) return false;
        return true;
    }
    int maxers(vector<int> a,int n,int pos){
      //  if(pos=0)
       // for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<"\n";
        if(pos==0) return a[0];
        int sum=0;
        int c=1;
        for(int i=pos;i>=0;i--,c++){
            sum += a[i]*c;
        }
        //cout<<sum;
        return sum;
    }
    int maxSatisfaction(vector<int>& a) {
        int n = a.size();
        if(all_neg(a,n)) return 0;
        sort(a.begin(),a.end(),greater<int>());
        for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<"\n";
        int maxa = INT_MIN;
        for(int i=0;i<n;i++){
            maxa = max(maxa,maxers(a,n,i));
        }
        return maxa;
    }
};