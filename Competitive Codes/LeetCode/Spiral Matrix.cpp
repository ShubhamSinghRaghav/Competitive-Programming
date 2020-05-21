class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        vector<int> res;
        int R = matrix.size();
        int C = matrix[0].size();
        vector< vector<bool> > visited(R,vector<bool>(C,false));
        int dr[4]={0,1,0,-1};
        int dc[4]={1,0,-1,0};
        int r=0,c=0,di=0,cr,cc;
        for(int i=0;i<R*C;i++){
            res.push_back(matrix[r][c]);
            visited[r][c] = true;
            cr = r + dr[di];
            cc = c + dc[di];
            if(cr>=0 and cr<R and cc>=0 and cc<C and !visited[cr][cc]){
                r = cr;
                c = cc;
            }else{
                di = (di+1)%4;
                r = r + dr[di];
                c = c + dc[di];
            }
        }
        return res;
    }
};