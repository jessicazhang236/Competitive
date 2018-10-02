#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+4;
int N, X, A[MAXN], B[MAXN];
ll ans;
int main() {
    scanf("%d%d", &N, &X);
    for (int n=1; n<=N; n++) {
        scanf("%d%d", &A[n], &B[n]);
    }
    if (X==1) {
        for (int n=1; n<=N; n++) {
            ans+=max(0LL, (B[n]-A[n]-1LL));
        }
        printf("%lld\n", ans);
        return 0;
    }
    if (N<=8) {
        ans=0x3f3f3f3f3f3f3f3f;
        do{
            ll cur=0LL;
            bool flg=0;
            for (int n=1; n<=N; n++) {
                if (A[n]>B[n]) {
                    flg=1;
                    break;
                }
                cur+=max(0, (B[n]-A[n]-1)/X);
            }
            if (!flg) ans=min(ans, cur);
        }while(next_permutation(B+1, B+1+N));
        printf("%lld\n", ans);
    }
}
