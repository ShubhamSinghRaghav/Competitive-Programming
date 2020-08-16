/*

The tribe soon discovers that just communication is not enough and wants to meet each other to form a joint force against the terminator. But there is a deep canyon that needs to crossed. Points have been identified on both sides on which bridge ends can be made. But before the construction could be started, a witch Chudael predicted that a bridge can only be built between corresponding end points, i.e. a bridge starting from the ith end point on one side can only end on the ith end point on the other side, where the position of end points is seen in the order in which the points were identified. If not, it would lead to the end of the tribe. The tribe just wants to make as many non-cutting bridges as possible, with the constraint in mind. Bridges "cut" if and only if they have exactly one common point that is not an end point.

Input Format
The first line of the input contains test cases t (1<=t<=50). It is followed by 3*t lines, 3 for each test case. The first line of input for each test case contains the number of end points identified on each side, n (1<=n<=10^3). The second line contains x-coordinates of end points identified on the first side and similiarly the third line contains the x-coordinates of corresponding end points identified on the other side. The end points are inputted in the order in which they were identified. The x-coordinates can range between -10^3 to 10^3.

Constraints
Output Format
You are required to output a single line for each test case. The line contains a single integer – the maximum number of bridges possible with the constraints explained above.

Sample Input
3
4
2 5 8 10
6 4 1 2
3
5 3 10
6 4 1
6
1 2 3 4 5 6
3 4 5 6 1 2
Sample Output
2
2
4

*/
#include <algorithm>
#include <cstdio>
#include <utility>
#include <iostream>
using namespace std;
int st[1003], fin[1003];
pair<int, int> edge[1003];
int lis[1003];
int N;
int ans;
void LIS(){
    sort(edge, edge+N);
    ans = 0;
    for(int i=0;i<N;++i){
        lis[i] = 1;
        for(int j=i-1;j>=0;--j){
            if(edge[j].second <= edge[i].second){
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        ans = max(ans, lis[i]);
    }
    printf("%d\n", ans);
}

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &N);
        for(int i=0;i<N;++i){
            scanf("%d", &st[i]);
        }
        for(int i=0;i<N;++i){
            scanf("%d", &fin[i]);
        }
        for(int i=0;i<N;++i){
            edge[i] = make_pair(st[i], fin[i]);
        }
        LIS();
    }
    return 0;
}