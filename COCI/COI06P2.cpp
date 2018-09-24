#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+4, LN=20;
int N, E, Q, lca[LN][MAXN], cnt, dfn[MAXN], low[MAXN], dep[MAXN], dfn2[MAXN];
vector<int> adj[MAXN];
void dfs(int cur, int src) {
    dfn[cur]=low[cur]=++cnt;
    for (int v: adj[cur]) {
        if (v==src) continue;
        if (!dfn[v]) {
            dep[v]=dep[cur]+1;
            lca[0][v]=cur;
            dfs(v, cur);
            low[cur]=min(low[cur], low[v]);
        }
        else low[cur]=min(low[cur], dfn[v]);
    }
    dfn2[cur]=++cnt;
}
int adv(int a, int d) {
    int ans=a;
    int pos=0;
    for (int i=19; i>=0; i--) {
        if (pos+(1<<i)<=d) {
            pos+=1<<i;
            ans=lca[i][ans];
        }
    }
    return ans;
}
bool par(int u, int v) {
    return dfn[u]<=dfn[v]&&dfn2[u]>=dfn2[v];
}
int main() {
    memset(lca, -1, sizeof lca);
    scanf("%d%d", &N, &E);
    for (int e=1, a, b; e<=E; e++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%d", &Q);
    dfs(1, -1);
    for (int i=1; i<LN; i++) {
        for (int n=1; n<=N; n++) lca[i][n]=lca[i-1][lca[i-1][n]];
    }
    for (int q=1, t, a, b, u, v, f, s; q<=Q; q++) {
        scanf("%d%d%d%d", &t, &a, &b, &u);
        if (t==1) {
            scanf("%d", &v);
            if (par(v, u)) {
                f=v, s=u;
            }
            else {
                f=u, s=v;
            }
            if (low[s]<=dfn[f]) printf("yes\n");
            else if (par(s, a)&&par(s, b)) printf("yes\n");
            else if (!par(s, a)&&!par(s, b)) printf("yes\n");
            else printf("no\n");
        }
        else {
            if (!par(u, a)&&!par(u, b)) printf("yes\n");
            else if (par(u, a)&&!par(u, b)) {
                v=adv(a, dep[a]-dep[u]-1);
                if (low[v]<dfn[u]) printf("yes\n");
                else printf("no\n");
            }
            else if (!par(u, a)&&par(u, b)) {
                v=adv(b, dep[b]-dep[u]-1);
                if (low[v]<dfn[u]) printf("yes\n");
                else printf("no\n");
            }
            else {
                int va=adv(a, dep[a]-dep[u]-1);
                int vb=adv(b, dep[b]-dep[u]-1);
                if (low[va]<dfn[u]&&low[vb]<dfn[u]) printf("yes\n");
                else if (va==vb) printf("yes\n");
                else printf("no\n");
            }
        }
    }
}
