#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+4;
int N, Q, cnt, LCA[20][MAXN], num[MAXN], depth[MAXN];
vector<int> ste[MAXN];
vector<int> adj[MAXN];
void DFS(int cur, int src) {
    LCA[0][cur]=src;
    ste[cur].push_back(++cnt);
    for (int i: adj[cur]) {
        depth[i]=depth[cur]+1;
        DFS(i, cur);
        ste[cur].push_back(++cnt);
    }
}
void build() {
    DFS(1, -1);
    for (int i=1; i<=19; i++) {
        for (int j=1; j<=N; j++) {
            if (~LCA[i-1][j]) LCA[i][j]=LCA[i-1][LCA[i-1][j]];
            else LCA[i][j]=-1;
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
    scanf("%d", &N);
    for (int n=1, C; n<=N; n++) {
        scanf("%d", &C);
        for (int c=1, d; c<=C; c++) {
            scanf("%d", &d);
            adj[n].push_back(d);
        }
    }
    build();
    scanf("%d", &Q);
    for (int q=1, u, v; q<=Q; q++) {
        scanf("%d%d", &u, &v);
        if (u==v) printf("0\n");
        else if (ste[u][0]<ste[v][0]) {
            int rt=lca(u, v);
            printf("%d\n", ste[v][0]-ste[rt][0]-depth[u]+depth[rt]);
        }
        else {
            int rt=lca(u, v);
            int i=lower_bound(ste[rt].begin(), ste[rt].end(), ste[u][0])-ste[rt].begin();
            printf("%d\n", ste[rt][i]-ste[rt][i-1]+ste[v][0]-ste[rt][0]-depth[u]+depth[rt]);
        }
    }
}
