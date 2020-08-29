/*
Gary has a board of size NxM. Each cell in the board is a coloured dot. 
There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). 
Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. 
Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. 
Also, dk and d1 should also be adjacent. 
Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. 
Your task is to determine if there exists a cycle on the board.
Assume input to be 0-indexed based.
Input Format :
Line 1 : Two integers N and M, the number of rows and columns of the board
Next N lines : a string consisting of M characters, expressing colors of dots in each line. 
Each character is an uppercase Latin letter.
Output Format :
Return 1 if there is a cycle else return 0
Constraints :
2 ≤ N, M ≤ 50
Sample Input :
3 4
AAAA
ABCA
AAAA
Sample Output :
1
*/

int xdir[4] = {1,-1,0,0};
int ydir[4] = {0,0,1,-1};
int visited[MAXN][MAXN];

bool eligible(char board[][MAXN], int n, int m, int i, int j, char curr){
    if(i>=0 && j>=0 && i<n && j<m && board[i][j]==curr)
        return true;
    return false;
}

int path_helper(char board[][MAXN], int n, int m, int i, int j, int fromx, int fromy, char curr){
    if(i>n || j>m)
        return 0;
    if(visited[i][j] == 1)
        return 1;
    if(board[i][j] != curr)
        return 0;

    visited[i][j] = 1;
    for(int k = 0 ; k < 4 ; k++){
        int dx = i + xdir[k];
        int dy = j + ydir[k];
        if(eligible(board,n,m,dx,dy,curr) && (dx!=fromx || dy!=fromy)){
            if(path_helper(board, n, m, dx, dy, i, j, curr) == 1)
                return 1;
        }
    }
    return 0;
}

int solve(char board[][MAXN],int n, int m)
{
    int ans = 0;
    memset(visited,0,sizeof(visited));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(visited[i][j] != 1){
                char curr = board[i][j];
                ans = path_helper(board, n, m, i, j, -1, -1, curr);
                if(ans==1)
                    return 1;
            }
        }
    }
    return ans;
}