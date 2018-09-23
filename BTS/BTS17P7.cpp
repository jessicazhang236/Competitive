#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+4;
int N, S, LCA[20][MAXN], depth[MAXN];
ll dif[MAXN], delta[MAXN], ans[MAXN];
vector<int> adj[MAXN];
void DFS(int cur, int src) {
    for (int a: adj[cur]) {
        if (a==src) continue;
        LCA[0][a]=cur;
        depth[a]=depth[cur]+1;
        DFS(a, cur);
    }
}
void DFS2(int cur, int src) {
    ans[cur]=dif[cur];
    for (int a: adj[cur]) {
        if (a==src) continue;
        DFS2(a, cur);
        ans[cur]+=ans[a]+delta[a];
        delta[cur]+=delta[a];
    }
}
inline void build() {
    for (int i=1; i<=19; i++) {
        for (int j=1; j<=N; j++) {
            if (~LCA[i-1][j]) LCA[i][j]=LCA[i-1][LCA[i-1][j]];
        }
    }
}
inline int lca(int x, int y) {
    if(depth[x]<depth[y]) swap(x, y);
    for(int i=19;i>=0;i--) {
        if(~LCA[i][x]&&depth[LCA[i][x]]>=depth[y]) x=LCA[i][x];
    }
    if(x==y) return x;
    for(int i=19;i>=0;i--) {
        if(~LCA[i][x]&&LCA[i][x]^LCA[i][y]) {
            x=LCA[i][x];
            y=LCA[i][y];
        }
    }
    return LCA[0][x];
}
int main() {
    scanf("%d%d", &N, &S);
    for (int n=1, x, y; n<N; n++) {
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(LCA, -1, sizeof LCA);
    DFS(1, 1);
    build();
    for (int s=1, a, b, t; s<=S; s++) {
        scanf("%d%d%d", &a, &b, &t);
        int lab=lca(a, b);
        int lat=lca(a, t);
        int lbt=lca(b, t);
        int labt=lca(lab, t);
        int dat=depth[a]+depth[t]-2*depth[lat];
        int dabt=depth[lab]+depth[t]-2*depth[labt];
        int dbt=depth[b]+depth[t]-2*depth[lbt];
        int datt=depth[t]-depth[lat];
        int pab=LCA[0][lab];
        dif[a]+=dat;
        dif[b]+=dbt;
        dif[lab]-=dabt;
        if (pab!=-1) dif[pab]-=dabt;
        delta[a]-=1;
        delta[b]-=1;
        if (lat!=lab&&lbt==lab) delta[lat]+=2;
        else if (lbt!=lab&&lat==lab) delta[lbt]+=2;
        else delta[lab]+=2;
    }
    DFS2(1, 1);
    for (int n=1; n<=N; n++) printf("%lld ", ans[n]);
}
