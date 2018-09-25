#include <bits/stdc++.h>
using namespace std;
const int MAXN=504, MOD=1e9+7;
int N, K;
typedef long long ll;
ll dp[2][MAXN][MAXN], psa[MAXN];
int main() {
    scanf("%d%d", &N, &K);
    dp[0][0][0]=1;
    for (int n=1; n<=N; n++) {
        for (int i=0; i<=N; i++) {
            if (i<N) {
                memset(psa, 0, sizeof psa);
                psa[0]=dp[0][i+1][0];
                for (int k=1; k<=K; k++) psa[k]=(psa[k-1]+dp[0][i+1][k])%MOD;
            }
            for (int k=0; k<=K; k++) {
                dp[1][i][k]=(dp[1][i][k]+dp[0][i][k])%MOD;
                if (i) dp[1][i][k]=(dp[1][i][k]+dp[0][i-1][k])%MOD;
                if (i<N) {
                    dp[1][i][k]+=psa[k];
                    if ((k-i)>0) dp[1][i][k]+=(MOD-psa[k-i-1]);
                    dp[1][i][k]%=MOD;
                }
            }
        }
        for (int i=0; i<=N; i++) {
            for (int k=0; k<=K; k++) {
                dp[0][i][k]=dp[1][i][k];
                dp[1][i][k]=0;
            }
        }
    }
    printf("%lld", dp[0][0][K]);
}
