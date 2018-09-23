// two purposes of pies: occupy a position (low) or get the value (high)
// sort pies, call two endpoints, check each position if we should occupy a position, inject a pie, or don't do anything
// states: dp[pos][flag: 0--have/ 1--haven't picked up previous][l: m pies][r: m pies]
#include <bits/stdc++.h>
using namespace std;
int N, M, A[3004], B[104], DP[3004][2][104][104];
inline int pies(int pos, int flag, int l, int r) {
    int a=DP[pos][flag][l][r];
    if (a!=-1)
        return a;
    if (pos>N) {
        if (l<=r) {
            if (flag==1) return DP[pos][flag][l][r]=B[r]+pies(pos, 0, l, r-1);
            return DP[pos][flag][l][r]=pies(pos, 1, l+1, r);
        }
        return DP[pos][flag][l][r]=0;
    }
    if (flag==1) {
        a=max(pies(pos, 0, l, r), A[pos]+pies(pos+1, 0, l, r));
        if (l<=r) return DP[pos][flag][l][r]=max(a, B[r]+pies(pos, 0, l, r-1));
        return DP[pos][flag][l][r]=a;
    }
    else {
        a=pies(pos+1, 1, l, r);
        if (l<=r) return DP[pos][flag][l][r]=max(a, pies(pos, 1, l+1, r));
        return DP[pos][flag][l][r]=a;
    }
}
int main() {
    memset(DP, -1, sizeof DP);
    scanf("%d", &N);
    for (int n=1; n<=N; n++) scanf("%d", &A[n]);
    scanf("%d", &M);
    for (int m=1; m<=M; m++) scanf("%d", &B[m]);
    sort(B, B+M+1);
    printf("%d", pies(1, 1, 1, M));
}
