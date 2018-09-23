#include <bits/stdc++.h>
using namespace std;
int N, A[4], ans;
void solve(int cur, int nxt, int card) {
    if (card==3) {
        if (cur+nxt<=24) ans=max(ans, cur+nxt);
        if (cur-nxt<=24) ans=max(ans, cur-nxt);
        if (cur*nxt<=24) ans=max(ans, cur*nxt);
        if (nxt&&!(cur%nxt)&&cur/nxt<=24) ans=max(ans, cur/nxt);
        return;
    }
    solve(cur+nxt, A[card+1], card+1);
    solve(cur-nxt, A[card+1], card+1);
    solve(cur*nxt, A[card+1], card+1);
    if (nxt&&!(cur%nxt)) solve(cur/nxt, A[card+1], card+1);
    solve(cur, nxt+A[card+1], card+1);
    solve(cur, nxt-A[card+1], card+1);
    solve(cur, nxt*A[card+1], card+1);
    if (A[card+1]&&!(nxt%A[card+1])) solve(cur, nxt/A[card+1], card+1);
}
int main() {
    scanf("%d", &N);
    for (int n=0, a, b, c, d; n<N; n++) {
        scanf("%d%d%d%d", &A[0], &A[1], &A[2], &A[3]);
        ans=0;
        for (int i=0; i<24; i++) {
            solve(A[0], A[1], 1);
            next_permutation(A, A+4);
        }
        printf("%d\n", ans);
    }
}
