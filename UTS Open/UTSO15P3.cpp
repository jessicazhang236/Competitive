#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+4, MOD=1e9+7;
int N, M;
ll dp[2][MAXN];
int main() {
    scanf("%d %d", &N, &M);
    if (M==1) printf("1\n");
    else if (M==2) {
        dp[0][1]=dp[0][2]=1;
        for (int n=3; n<=N; n++)
            dp[0][n]=(dp[0][n-1]+dp[0][n-3])%MOD;
        printf("%lld\n", dp[0][N]);
    }
    else {
        dp[1][1]=dp[1][2]=dp[1][3]=1;
        dp[1][4]=2;
        dp[1][5]=6;
        dp[1][6]=14;
        dp[1][7]=28;
        dp[1][8]=56;
        for (int n=9; n<=N+1; n++) {
            dp[1][n]=(2*dp[1][n-1]%MOD+2*dp[1][n-3]%MOD+dp[1][n-4]+dp[1][n-5]-dp[1][n-2]-dp[1][n-7]-dp[1][n-8]+MOD+MOD+MOD)%MOD;
        }
        printf("%lld\n",dp[1][N]);
    }
}
