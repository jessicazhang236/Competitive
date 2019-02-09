#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+4, MOD=1e9+7;
stack<int> S;
int N, M, dfn[MAXN], low[MAXN], cnt1, scc[MAXN], cnt2, loot[MAXN], V[MAXN], dp[MAXN][2], cnt[MAXN][2];
vector<int> adj[MAXN], adj2[MAXN];
bool vis[MAXN];
void Tarjan(int src) {
    dfn[src]=low[src]=++cnt1;
    vis[src]=1;
    S.push(src);
    for (int i: adj[src]) {
        if (!dfn[i]) {
            Tarjan(i);
            low[src]=min(low[src], low[i]);
        }
        else if (vis[i]) low[src]=min(low[src], dfn[i]);
    }
    if (low[src]==dfn[src]) {
        int a;
        do {
            a=S.top();
            S.pop();
            vis[a]=0;
            scc[a]=cnt2;
            loot[cnt2]+=V[a];
        } while (a!=src);
        cnt2++;
    }
}
void build() {
    for (int n=1; n<=N; n++) {
        for (int i: adj[n]) {
            int p=scc[n];
            int q=scc[i];
            if (p==q) continue;
            adj2[p].push_back(q);
        }
    }
    for (int i=0; i<cnt2; i++) {
        sort(adj2[i].begin(), adj2[i].end());
        adj2[i].erase(unique(adj2[i].begin(), adj2[i].end()),adj2[i].end());
    }
}
void dfs(int n) {
    vis[n]=1;
    if (n==scc[N]) {
        cnt[n][0]=cnt[n][1]=1;
        dp[n][1]=loot[n];
        return;
    }
    for (int i: adj2[n]) {
        if (!vis[i]) dfs(i);
        if (dp[i][0]+loot[n]>dp[n][1]) {
            dp[n][1]=dp[i][0]+loot[n];
            cnt[n][1]=cnt[i][0];
        }
        else if (dp[i][0]+loot[n]==dp[n][1]) cnt[n][1]=(cnt[n][1]+cnt[i][0])%MOD;
        if (dp[i][0]>dp[n][0]) {
            dp[n][0]=dp[i][0];
            cnt[n][0]=cnt[i][0];
        }
        else if (dp[i][0]==dp[n][0]) cnt[n][0]=(cnt[n][0]+cnt[i][0])%MOD;
        if (dp[i][1]>dp[n][0]) {
            dp[n][0]=dp[i][1];
            cnt[n][0]=cnt[i][1];
        }
        else if (dp[i][1]==dp[n][0]) cnt[n][0]=(cnt[n][0]+cnt[i][1])%MOD;
    }
}
int main() {
    scanf("%d%d", &N, &M);
    for (int n=1; n<=N; n++) scanf("%d", &V[n]);
    for (int m=1, a, b; m<=M; m++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
    }
    for (int n=1; n<=N; n++) {
        if (!dfn[n]) Tarjan(n);
    }
    memset(vis, 0, sizeof vis);
    build();
    int m=scc[1];
    dfs(m);
    if (dp[m][0]>dp[m][1]) printf("%d %d\n", dp[m][0], cnt[m][0]);
    else if (dp[m][0]<dp[m][1]) printf("%d %d\n", dp[m][1], cnt[m][1]);
    else printf("%d %d\n", dp[m][1], (cnt[m][0]+cnt[m][1])%MOD);
}
