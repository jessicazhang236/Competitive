#include <bits/stdc++.h>
using namespace std;
int N, K, Max, ans, mod[100004];
int main() {
    scanf("%d%d", &N, &K);
    memset(mod, 0x3f, sizeof mod);
    for (int n=1, x; n<N; n++) {
        scanf("%d", &x);
        mod[n%K]=min(mod[n%K], x);
    }
    for (int k=0; k<K; k++) {
        if (mod[k]!=0x3f3f3f3f) {
            ans+=mod[k];
            if (mod[k]>Max) Max=mod[k];
        }
    }
    printf("%d", ans-Max);
}
