#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
const int MAXN=5e5+4;
int sz[MAXN], up[MAXN], level[MAXN], cng[MAXN*20];
bool done[MAXN];
typedef pair<int, long long> pil;
typedef long long ll;
ll ans[MAXN], st[20][MAXN];
vector<pil> adj[MAXN];
int dfs(int u, int p) {
    sz[u]=1;
    for (auto m: adj[u]) {
        int v=m.first;
        if (v!=p&&!done[v]) {
            sz[u]+=dfs(v, u);
        }
    }
    return sz[u];
}
int getCentre(int u, int p, int tot) {
    for (auto m: adj[u]) {
        int v=m.first;
        if (v!=p&&!done[v]&&sz[v]*2>tot) return getCentre(v, u, tot);
    }
    return u;
}
void update(int cur, int par, int l, ll dist) {
    st[l][cur]=dist;
    for (auto p: adj[cur]) {
        if (p.first!=par&&!done[p.first]) update(p.first, cur, l, dist+p.second);
    }
}
void solve(int rt, int par, int lvl) {
    up[rt]=par;
    level[rt]=lvl;
    update(rt, -1, lvl, 0LL);
    done[rt]=1;
    for (auto e: adj[rt]) {
        if (!done[e.first]) {
            solve(getCentre(e.first, -1, dfs(e.first, rt)), rt, lvl+1);
        }
    }
}
void Init(int N, int A[], int B[], int D[]) {
    for (int n=0; n<N-1; n++) {
        adj[A[n]].emplace_back(B[n], D[n]);
        adj[B[n]].emplace_back(A[n], D[n]);
    }
    memset(ans, 0x3F, sizeof ans);
    solve(getCentre(0, -1, dfs(0, -1)), -1, 0);
}
ll Query(int S, int X[], int T, int Y[]) {
    int cnt=0;
    ll best=INF;
    for (int s=0; s<S; s++) {
        int cur=X[s];
        int x=cur;
        while (cur!=-1) {
            if (ans[cur]==INF) cng[++cnt]=cur;
            ans[cur]=min(ans[cur], st[level[cur]][x]);
            cur=up[cur];
        }
    }
    for (int t=0; t<T; t++) {
        int y=Y[t];
        int cur=y;
        while (cur!=-1) {
            best=min(best, ans[cur]+st[level[cur]][y]);
            cur=up[cur];
        }
    }
    for (int i=1; i<=cnt; i++) ans[cng[i]]=INF;
    return best;
}
int main() {
    int n, q, s, t;
    scanf("%d%d", &n, &q);
    int a[n], b[n], d[n];
    for (int i=0; i<n-1; i++) {
        scanf("%d%d%d", &a[i], &b[i], &d[i]);
    }
    Init(n, a, b, d);
    for (int i=0; i<q; i++) {
        scanf("%d%d", &s, &t);
        int x[s], y[t];
        for (int i=0; i<s; i++) scanf("%d", &x[i]);
        for (int i=0; i<t; i++) scanf("%d", &y[i]);
        printf("%lld\n", Query(s, x, t, y));
    }
}
