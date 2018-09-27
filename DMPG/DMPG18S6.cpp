#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN=1e5+4;
int N, M, dfn[MAXN], low[MAXN], pt, cnt, par[MAXN], tree, sz[MAXN], st, ans=0x3f3f3f3f;
bool ap[MAXN], dne=1, vis[MAXN];
stack<int> stk;
vector<int> adj[MAXN], adj2[2*MAXN];
vector<vector<int>> comps;
void Tarjan(int cur, int src) {
    bool flg=0;
    stk.push(cur);
    dfn[cur]=low[cur]=++cnt;
    int child=0;
    for (int a: adj[cur]) {
        if (a==src) continue;
        child++;
        if (!dfn[a]) {
            par[a]=cur;
            Tarjan(a, cur);
            //printf("%d %d\n", a, cur);
            low[cur]=min(low[cur], low[a]);
            if (par[cur]&&low[a]>=dfn[cur]) {
                ap[cur]=1;
                flg=1;
                dne=0;
            }
        }
        else low[cur]=min(low[cur], dfn[a]);
    }
    if (!par[cur]&&child>1) {
        ap[cur]=1;
        flg=1;
        dne=0;
    }
    if (flg) {
        st=cur;
        tree++;
        int w=0;
        while (!stk.empty()) {
            int b=stk.top();
            stk.pop();
            //printf("%d %d\n", b, cur);
            if (!ap[b]) w++;
            if (b==cur) break;
        }
        sz[cur]=1;
        sz[tree]=w;
        adj2[cur].push_back(tree);
        adj2[tree].push_back(cur);
    }
}
void dfs(int cur, int src) {
    int Max=0;
    for (int a: adj2[cur]) {
        if (a==src) continue;
        dfs(a, cur);
        sz[cur]+=sz[a];
        Max=max(Max, sz[a]);
    }
    if (Max<ans&&ap[cur]==1) {
        ans=Max;
        pt=cur;
    }
}
int main() {
    scanf("%d%d", &N, &M);
    tree=N;
    for (int m=1, x, y; m<=M; m++) {
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int n=1; n<=N; n++) {
        if (!dfn[n]) Tarjan(n, n);
    }
    if (dne) {
        printf("-1 -1");
        return 0;
    }
    dfs(st, st);
    printf("%d %d", pt, ans);
}
