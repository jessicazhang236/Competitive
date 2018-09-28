#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+4;
int K, N, c[MAXN];
ll dp[MAXN];
int main() {
    scanf("%d%d", &K, &N);
    if (K>N+1) {
        printf("-1");
        return 0;
    }
    for (int n=1; n<=N; n++) scanf("%d", &c[n]);
    dp[1]=c[1];
    dp[2]=max(c[2], c[1]);
    if (K<=2) {
        printf("%lld", max(c[1], c[2]));
        return 0;
    }
    for (int n=3; n<=N+1; n++) dp[n]=max((ll)c[n], (ll)c[n-1]+dp[n-2]);
    printf("%lld", dp[K]);
}
