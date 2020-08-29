/*
Gary is a teacher at XYZ school. To reward his N students he bought a packet of N candies all with different flavours. 
But the problem is some students like certain flavour while some doesn't. 
Now Gary wants to know the number of ways he can distribute these N candies to his 
N students such that every student gets exactly one candy he likes.
Input Format :
Line 1 : An integer N (1<= N <= 16) denoting number of students and candies.
Next N lines : N integers describing the preferences of one student. 
1 at i'th (0 <= i < N) position denotes that this student likes i'th candy , 0 means he doesn't.
Assume input to be 0-indexed based.
Output Format :
Return the number of ways Gary can distribute these N candies to his N students such that every student gets exactly one candy he likes.``
Sample Input:
3
1 1 1
1 1 1
1 1 1
Sample Output:
6
*/


int solve1(int like[][MAXN],int n,int child,int mask,int *dp){
    if(child>=n) return 1;
    if(dp[mask]!=-1) return dp[mask];
    int res = 0;
    for(int i=0;i<n;i++){
        if(!(mask&(1<<i)) && like[child][i]==1){
            res += solve1(like,n,child+1,mask|(1<<i),dp);
        }
    }
    dp[mask] = res;
    return res;
}

long long solve(int like[][MAXN],int n){
    int *dp = new int[1<<n];
    for(int i=0;i<(1<<n);i++) dp[i]=-1;
    int re = solve1(like,n,0,0,dp);
    delete []dp;
    return re;
}