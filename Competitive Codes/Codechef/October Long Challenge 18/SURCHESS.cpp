#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=200;

int n,m,te,MIN[maxn+5][maxn+5][maxn+5][2];char pic[maxn+5][maxn+5];
int ans[maxn+5][maxn+5][maxn+5][2],MAX[maxn*maxn+5];

inline void Make(){
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            int lst='0',now=pic[i][j]!=lst;MIN[i][j][j][0]=now;
            for (int k=j+1;k<=m;k++) lst^=1,now+=pic[i][k]!=lst,MIN[i][j][k][0]=now;
            lst='1';now=pic[i][j]!=lst;MIN[i][j][j][1]=now;
            for (int k=j+1;k<=m;k++) lst^=1,now+=pic[i][k]!=lst,MIN[i][j][k][1]=now;
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            for (int k=1,D=i,R=j;D<=n&&R<=m;k++,R++,D++){
                int lst=0,now=0;for (int t=i;t<=D;t++) now+=MIN[t][j][R][lst],lst^=1;MAX[now]=max(MAX[now],k);
                lst=1;now=0;for (int t=i;t<=D;t++) now+=MIN[t][j][R][lst],lst^=1;MAX[now]=max(MAX[now],k);
            }
    for (int i=1;i<=n*m;i++) MAX[i]=max(MAX[i],MAX[i-1]);
}
int main(){
    scanf("%d%d",&n,&m);for (int i=1;i<=n;i++) scanf("%s",pic[i]+1);
    for (Make(),scanf("%d",&te);te;te--){
        int x;scanf("%d",&x);if (x>n*m) x=n*m;
        printf("%d\n",MAX[x]);
    }return 0;
}
