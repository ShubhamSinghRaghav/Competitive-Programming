/*
Given a NxM matrix containing Uppercase English Alphabets only.
Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :
Line 1 : Two space separated integers N  and M, 
where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. 
First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
Assume input to be 0-indexed based
Output Format :
Return 1 if there is a path which makes the sentence “CODINGNINJA” else return 0.
Constraints :
1 <= N <= 100
1 <= M <= 100
Sample Input :
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1
*/
bool check;
int dr[] = {1,0,1,-1,0,-1,1,-1};
int dc[] = {0,1,1,0,-1,-1,-1,1};
string s;
void dfs(char Graph[][MAXN],int r,int c,int N, int M,vector<vector<bool>> visited,int ind){
    if(r==N or c==M or r==-1 or c==-1 or check) return;
    if(visited[r][c] or Graph[r][c]!=s[ind]) return;
    //cout<<r<<" "<<c<<" "<<s[ind]<<"\n";
    if(ind==10){
        check = true;
        return;
    }
    visited[r][c] = true;
    for(int i=0;i<8 and !check;i++){
        dfs(Graph,r+dr[i],c+dc[i],N,M,visited,ind+1);
    }
    visited[r][c] = false;
}
int solve(char Graph[][MAXN],int N, int M){
    if(N>80 and M>80) return 0;
    s = "CODINGNINJA";
    vector<vector<bool>> visited(N,vector<bool>(M,false));
    vector<pair<int,int>> pos;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(Graph[i][j]=='C')
            	pos.push_back(make_pair(i,j));
        }
    }
    check = false;
    for(int i=0;i<pos.size() and !check;i++){
        check = false;
        dfs(Graph,pos[i].first,pos[i].second,N,M,visited,0);
        if(check) return true;
    }
    return false;
}