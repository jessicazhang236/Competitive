#include <bits/stdc++.h>
using namespace std;
int T, N, K, W, val[30004], single[30004], DP[504][60004];
int main() {
    scanf("%d", &T);
    for (int t=0; t<T; t++) {
        scanf("%d%d%d", &N, &K, &W);
        memset(DP, 0, sizeof DP);
        memset(single, 0, sizeof single);
        for (int n=1; n<=N; n++)
            scanf("%d", &val[n]);
        for (int w=1; w<=W; w++)
            single[1]+=val[w];
        for (int n=1; n<N; n++) {
            if (n<=N-W) single[n+1]=single[n]-val[n]+val[n+W];
            else single[n+1]=single[n]-val[n];
        }
        for (int k=1; k<=K; k++) {
            for (int n=N; n>0; n--) DP[k][n]=max(DP[k-1][n+W]+single[n], DP[k][n+1]);
        }
        printf("%d\n", DP[K][1]);
    }
}
