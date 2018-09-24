#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAXN=504;
int N, M, art, nd, dfn[MAXN], low[MAXN], cnt, par[MAXN];
bool vis[MAXN], vis2[MAXN], ap[MAXN];
vector<int> adj[MAXN];
ull ans, ways=1LL;
void init() {
    cnt=nd=art=0;
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(par, 0, sizeof par);
    memset(vis, 0, sizeof vis);
    memset(vis2, 0, sizeof vis2);
    memset(ap, 0, sizeof ap);
    for (int n=1; n<=MAXN; n++) adj[n].clear();
    ans=0LL;
    ways=1LL;
    M=0;
}
void Tarjan(int src) {
    int child=0;
    vis[src]=1;
    dfn[src]=low[src]=++cnt;
    for (int a: adj[src]) {
        if (!vis[a]) {
            child++;
            par[a]=src;
            Tarjan(a);
            low[src]=min(low[src], low[a]);
            if (par[src]&&dfn[src]<=low[a]) ap[src]=1;
        }
        else if (a!=par[src]) low[src]=min(low[src], dfn[a]);
    }
    if (!par[src]&&child>1) ap[src]=1;
}
void dfs(int src) {
    vis[src]=vis2[src]=1;
    if (ap[src]) {
        art++;
        return;
    }
    nd++;
    for (int a: adj[src]) {
        if (vis2[a]) continue;
        dfs(a);
    }
}
int main() {
    scanf("%d", &N);
    while (N) {
        for (int n=1, a, b; n<=N; n++) {
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
            if (a<b) swap(a, b);
            M=max(M, a);
        }
        for (int m=1; m<=M; m++) {
            if (!dfn[m]) Tarjan(m);
        }
        memset(vis, 0, sizeof vis);
        for (int m=1; m<=M; m++) {
            if (ap[m]||vis[m]) continue;
            dfs(m);
            if (art==1) {
                ans++;
                ways*=nd;
            }
            else if (art==0) {
                ans+=2;
                ways=ways*nd*(nd-1LL)/2LL;
            }
            art=nd=0;
            memset(vis2, 0, sizeof vis2);
        }
        printf("%llu %llu\n", ans, ways);
        init();
        scanf("%d", &N);
    }
}
