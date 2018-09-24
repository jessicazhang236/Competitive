#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int T, N, B, ans, DP[9][3004];
vector<pii> bag[9];
int main() {
    scanf("%d%d", &T, &N);
    for (int n=0, a, b, c; n<N; n++) {
        scanf("%d%d%d", &a, &b, &c);
        bag[c].emplace_back(a, b);
    }
    scanf("%d", &B);
    for (pii v: bag[1])
        DP[1][v.first]=v.second;
    for (int t=2; t<=T; t++) {
        for (pii v: bag[t]) {
            for (int b=B-v.first; b>0; b--) {
                if (DP[t-1][b]!=0&&DP[t-1][b]+v.second>DP[t][b+v.first]) DP[t][b+v.first]=DP[t-1][b]+v.second;
            }
        }
    }
    for (int b=1; b<=B; b++) ans=max(ans, DP[T][b]);
    if (ans!=0) printf("%d", ans);
    else printf("-1");
}
