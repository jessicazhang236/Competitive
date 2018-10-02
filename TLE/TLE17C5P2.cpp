#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN=1e5+4;
bool fwd, bck;
int N, D, X[MAXN], fwd_m=0x3f3f3f3f, fwd_M, bck_m, bck_M=0x3f3f3f3f;
int main() {
    scanf("%d%d", &N, &D);
    for (int n=1; n<=N; n++)
        scanf("%d", &X[n]);
    for (int d=1, i, j; d<=D; d++) {
        scanf("%d%d", &i, &j);
        if (X[i]<X[j]) {
            fwd=true;
            fwd_m=min(fwd_m, X[i]);
            fwd_M=max(fwd_M, X[j]);
        }
        else {
            bck=true;
            bck_m=max(bck_m, X[i]);
            bck_M=min(bck_M, X[j]);
        }
    }
    if (!fwd) {printf("%d", bck_m-bck_M); return 0;}
    if (!bck) {printf("%d", fwd_M-fwd_m); return 0;}
    int l=min(fwd_m, bck_M);
    int r=max(fwd_M, bck_m);
    int a1=bck_m-l+fwd_M-l;
    int a2=r-fwd_m+r-bck_M;
    printf("%d", min(a1, a2));
}
