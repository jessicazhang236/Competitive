#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> trio;
typedef long long ll;
bool compare(trio a, trio b) {
    return get<2>(a)<get<2>(b);
}
const int MAXN=50004;
int N, M, nodes[MAXN], total_edge, LCA[20][MAXN], depth[MAXN], weight[20][MAXN];
ll mst=0LL, ans=0x3f3f3f3f3f3f3f3f;
vector<pii> adj[MAXN];
vector<trio> paths, carrot;
inline void init() {
    for (int n=1; n<=N; n++) nodes[n]=n;
}
inline int findRoot(int i) {
    if (nodes[i]!=i) nodes[i]=findRoot(nodes[i]);
    return nodes[i];
}
inline void Merge(int i, int j) {
    nodes[findRoot(i)]=findRoot(j);
}
void DFS(int cur, int src) {
    for (auto i: adj[cur]) {
        int a=i.first;
        if (a==src) continue;
        LCA[0][a]=cur;
        depth[a]=depth[cur]+1;
        weight[0][a]=i.second;
        DFS(a, cur);
    }
}
inline void build() {
    for (int i=1; i<=19; i++) {
        for (int j=1; j<=N; j++) {
            if (~LCA[i-1][j]) {LCA[i][j]=LCA[i-1][LCA[i-1][j]]; weight[i][j]=max(weight[i-1][j], weight[i-1][LCA[i-1][j]]);}
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
inline int find_max (int x, int y) {
    int a=depth[x]-depth[y];
    int ans=0, p=0;
    while (x!=y) {
        if (a&(1<<p)) {
            ans=max(ans, weight[p][x]);
            x=LCA[p][x];
        }
        p++;
    }
    return ans;
}
int main() {
    scanf("%d%d", &N, &M);
    for (int m=1, a, b, c; m<=M; m++) {
        scanf("%d%d%d", &a, &b, &c);
        paths.emplace_back(a, b, c);
    }
    sort(paths.begin(), paths.end(), compare);
    init();
    for (auto m: paths) {
        int a=get<0>(m);
        int b=get<1>(m);
        int c=get<2>(m);
        if (findRoot(a)!=findRoot(b)) {
            total_edge++;
            mst+=c;
			Merge(a,b);
			adj[a].emplace_back(b, c);
            adj[b].emplace_back(a, c);
        }
        else carrot.push_back(m);
    }
    if (total_edge<N-1) {printf("-1"); return 0;}
    LCA[0][1]=-1;
    DFS(1, 0);
    build();
    for (auto m: carrot) {
        int i=get<0>(m);
        int j=get<1>(m);
        int a=lca(i, j);
        int max_edge=max(find_max(i, a), find_max(j, a));
        if (get<2>(m)>max_edge) ans=min(ans, mst-max_edge+get<2>(m));
    }
    if (ans==0x3f3f3f3f3f3f3f3f) printf("-1");
    else printf("%lld", ans);
}
