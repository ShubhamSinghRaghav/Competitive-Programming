/*
Given a state of 3*3 Tic Tac Toe Board and two players 'x' and 'o', 
find the best optimal move possible for player 'x' specifying row and column. 
Also calculate the score by using the corresponding evaluation function.
Assume that there are 2 possible ways for 'x' to win the game from a give board state.
Move A : 'x' can win in 2 move
Move B : 'x' can win in 4 moves
The evaluation function may return a value of +10 for both moves A and B. 
Even though the move A is better because it ensures a faster victory, 
but we may choose B sometimes. To overcome this problem we subtract the depth value from the evaluated score. 
This means that in case of a victory it will choose the victory which takes least number of moves and in case of a loss 
it will try to prolong the game and play as many moves as possible. 
So the new evaluated value will be
Move A will have a value of +10 – 2 = 8
Move B will have a value of +10 – 4 = 6
Now since move A has a higher score compared to move B our AI will choose move A over move B. 
The same thing must be applied to the minimizer. 
Instead of subtracting the depth we add the depth value as the minimizer always tries to get, 
as negative a value as possible. Pseudocode implementation is as follows.
if maximizer has won:
    return WIN_SCORE – depth

else if minimizer has won:
    return LOOSE_SCORE + depth 
Input Format
 Integer 'n'(Number of given states of board)
 For each state we will have three values
 row number , column number , player name('x' or 'o')
Output Format
 (Evaluated Score) row: (Row Number) col: (Column Number)
Sample Input 1
5
0 0 x
0 1 o
0 2 x
1 0 o
1 2 x
Sample Output 1
10 row: 1 col: 1
*/

