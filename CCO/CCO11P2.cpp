#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e3+4;
typedef tuple<int, int, int> trio;
int S, N, E, dist[MAXN][3604], ans=0x3f3f3f3f;
struct way{
    int v, d, flag;
};
vector<way> adj[MAXN];
priority_queue<trio, vector<trio>, greater<trio>> Q;
int main() {
    scanf("%d%d%d", &S, &N, &E);
    for (int e=1, a, b, c, d; e<=E; e++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        adj[a].push_back({b, c, d});
        adj[b].push_back({a, c, d});
    }
    memset(dist, 0x3f, sizeof dist);
    dist[0][0]=0;
    Q.emplace(0, 0, 0);
    while (!Q.empty()) {
        auto cur=Q.top();
        Q.pop();
        int a=get<0>(cur);
        int b=get<1>(cur);
        int c=get<2>(cur);
        if (a>dist[c][b]) continue;
        for (auto w: adj[c]) {
            if (w.flag) {
                if (b+w.d>S) continue;
                if (dist[c][b]+w.d<dist[w.v][b+w.d]) {
                    dist[w.v][b+w.d]=dist[c][b]+w.d;
                    Q.emplace(dist[w.v][b+w.d], b+w.d, w.v);
                }
            }
            else {
                if (dist[c][b]+w.d<dist[w.v][b]) {
                    dist[w.v][b]=dist[c][b]+w.d;
                    Q.emplace(dist[w.v][b], b, w.v);
                }
            }
        }
    }
    for (int s=0; s<=S; s++) ans=min(ans, dist[N-1][s]);
    if (ans==0x3f3f3f3f) printf("-1\n");
    else printf("%d\n", ans);
}
