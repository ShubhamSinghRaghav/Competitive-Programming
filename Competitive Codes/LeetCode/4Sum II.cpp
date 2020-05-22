class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> m;
        for(auto a:A){
            for(auto b:B){
                m[a+b]++;
            }
        }int counter = 0; 
        for(auto c:C){
            for(auto d:D){
                counter+=m[-c-d];
            }
        }
        return counter;
    }
};
auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();