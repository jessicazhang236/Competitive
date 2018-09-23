#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+4;
typedef long long ll;
int N, x[MAXN], last;
ll psa[MAXN], dp[MAXN], a, b, c;
int main() {
    memset(dp, -0x3f, sizeof dp);
    dp[0]=0;
    scanf("%d%lld%lld%lld", &N, &a, &b, &c);
    for (int n=1; n<=N; n++) {
        scanf("%d", &x[n]);
        psa[n]=psa[n-1]+x[n];
    }
    for (int n=1; n<=N; n++) {
        for (int i=last; i<n; i++) {
            ll tmp=psa[n]-psa[i];
            ll cat=dp[i]+a*tmp*tmp+b*tmp+c;
            if (cat>=dp[n]) {
                dp[n]=cat;
                last=i;
            }
        }
    }
    printf("%lld\n", dp[N]);
}
