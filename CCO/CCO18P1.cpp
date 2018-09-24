#include <bits/stdc++.h>
using namespace std;
const int MAXN=1004;
string S, T;
int N, A[MAXN], B[MAXN], dp[MAXN][MAXN];
bool cmp(int a, int b) {
    if (S[a-1]=='W'&&A[a]<=B[b]) return 0;
    if (T[b-1]=='W'&&A[a]>=B[b]) return 0;
    return 1;
}
int main() {
    scanf("%d", &N);
    cin>>S;
    for (int n=1; n<=N; n++) scanf("%d", &A[n]);
    cin>>T;
    for (int n=1; n<=N; n++) scanf("%d", &B[n]);
    for (int n=1; n<=N; n++) {
        for (int i=1; i<=N; i++) {
            dp[n][i]=max(dp[n][i-1], dp[n-1][i]);
            if (S[n-1]==T[i-1]) continue;
            if (!cmp(n, i)) continue;
            dp[n][i]=max(dp[n][i], dp[n-1][i-1]+A[n]+B[i]);
        }
    }
    printf("%d", dp[N][N]);
}
