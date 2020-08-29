/*
You all must be familiar with the chess-board having 
8*8 squares of alternate black and white cells. Well, here 
we have for you a similar 
N*M size board with similar arrangement of black and white 
cells.
A few of these cells have Horses placed over them. 
Each horse is unique. Now these horses are not the 
usual horses which could jump to any of the 
8 positions they usually jump in. 
They can move only if there is another horse on one of the 8-positions that 
it can go to usually and then both the horses will swap their positions. 
This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! 
Given the state of the board, calculate answer. Sincethis answer may be quite large, calculate in modulo 
10^9+7
Input:
First line contains 
T which is the number of test cases.
T test cases follow first line of each containing three integers 
N, M and Q where 
N,M is the size of the board and 
Q is the number of horses on it.

Q lines follow each containing the 2 integers 
X and Y which are the coordinates of the Horses.
Output:
For each test case, output the number of photographs taken by photographer.
Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M
SAMPLE INPUT
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4
SAMPLE OUTPUT
4
2
*/

#include <bits/stdc++.h>

using namespace std;

long long n , m , q , x , y, tem1, tem2 , t, sum, mod = 1e9 + 7, ans;

bool vis [1000 + 1][1000 + 1];
bool arr [1000 + 1][1000 + 1];
long long factorial [1000000 + 1];

int dirc [8][2] = { {2 , 1}, {2 , -1}, {-2 , 1}, {-2, -1}, {1 , 2}, {1 , -2}, {-1, 2}, {-1, -2} };

void pre_calculate(){      

    factorial[0] = 1;
    for(long long i = 1; i <= 1e6; i++){
        factorial[i] = (factorial[i - 1] * i) % mod;
    }
}

void dfs(int x, int y){

    vis[x][y] = true;
    sum++;

    for(int i = 0; i < 8; i++){                     // check for the 8 movements

        int dx = x + dirc[i][0];
        int dy = y + dirc[i][1];

        if(dx <= 0 || dx > n || dy <= 0 || dy > m) continue;        // out of board
        if(vis[dx][dy] || !arr[dx][dy]) continue;                   // check if the cell is visited or doesn't contain a horse
        dfs(dx, dy);

    }

}


int main()
{

    pre_calculate();

    cin >> t;

    while(t--){

        cin >> n >> m >> q;

        ans = 1;

        for(int i = 0; i <= n; i++){                // reset arrays in each test case

            for(int j = 0; j <= m; j++){

                vis[i][j] = false;
                arr[i][j] = false;
            }
        }

        for(int i = 0; i < q; i++){

            cin >> tem1 >> tem2;
            arr[tem1][tem2] = true;
        }

        for(int i = 1; i <= n; i++){

            for(int j = 1; j <= m; j++){

                if(!vis[i][j] && arr[i][j]){

                    sum = 0;
                    dfs(i , j);                             // begin dfs from that unvisited horse (New group of connected horses)
                    ans = (ans * factorial[sum]) % mod;     // number of arrangements
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}