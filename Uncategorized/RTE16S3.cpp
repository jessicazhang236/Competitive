#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;
const int MAXN=6004;
int N, Q, LCA[15][MAXN], depth[MAXN];
ll w, dist[MAXN];
vector<pii> adj[MAXN];
void DFS(int cur, int src) {
    LCA[0][cur]=src;
    for (auto p: adj[cur]) {
        int a=p.first;
        if (a==src) continue;
        ll b=p.second;
        dist[a]=dist[cur]+b;
        depth[a]=depth[cur]+1;
        DFS(a, cur);
    }
}
void build() {
    DFS(0, -1);
    for (int i=1; i<=14; i++) {
        for (int j=0; j<N; j++) {
            if (~LCA[i-1][j]) LCA[i][j]=LCA[i-1][LCA[i-1][j]];
            else LCA[i][j]=-1;
        }
    }
}
inline int find_lca(int x, int y) {
    if(depth[x]<depth[y]) swap(x, y);
    for(int i=14;i>=0;i--) {
        if(~LCA[i][x]&&depth[LCA[i][x]]>=depth[y]) x=LCA[i][x];
    }
    if(x==y) return x;
    for(int i=14;i>=0;i--) {
        if(~LCA[i][x]&&LCA[i][x]^LCA[i][y]) {
            x=LCA[i][x];
            y=LCA[i][y];
        }
    }
    return LCA[0][x];
}
int main() {
    scanf("%d", &N);
    for (int n=1, a, b; n<N; n++) {
        scanf("%d%d%lld", &a, &b, &w);
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
    build();
    scanf("%d", &Q);
    for (int q=0, a, b; q<Q; q++) {
        scanf("%d%d", &a, &b);
        int lca=find_lca(a, b);
        printf("%lld\n", dist[a]+dist[b]-2*dist[lca]);
    }
}
