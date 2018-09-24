#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN=204, MOD=1e9+7;
int N, W, M, in[MAXN];
ll ans[MAXN], dp[MAXN][MAXN][2];
vector<pii> adj[MAXN];
char cmd;
void dfs(int src) {
    dp[src][0][0]=dp[src][1][1]=1;
    for (auto p: adj[src]) {
        dfs(p.first);
        for (int w=W, tmp, val; w>0; w--) {
            tmp=val=0;
            for (int i=0; i<=w; i++) {
                tmp=(tmp+dp[src][w-i][0]*(dp[p.first][i][0]+dp[p.first][i][1])%MOD)%MOD;
                val=(val+(dp[src][w-i][1]*dp[p.first][i][p.second])%MOD)%MOD;
            }
            dp[src][w][0]=tmp;
            dp[src][w][1]=val;
        }
    }
}
int main() {
    scanf("%d%d%d", &N, &W, &M);
    for (int m=1, a, b; m<=M; m++) {
        scanf(" %c%d%d", &cmd, &a, &b);
        adj[a].emplace_back(b, cmd=='D');
        in[b]++;
    }
    for (int n=1; n<=N; n++) {
        if (!in[n]) adj[0].emplace_back(n, 1);
    }
    dfs(0);
    printf("%lld", dp[0][W][0]);
}
