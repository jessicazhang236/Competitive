#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, T, K, D, check, prices[5004], dist[5004];
bool vis[5004];
vector<pii> roads[5004];
void Dijkstra() {
    while (check!=N) {
        int Min=0x3f3f3f3f;
        int m=-1;
        for (int n=1; n<=N; n++) {
            if (!vis[n]&&dist[n]<Min) {m=n; Min=dist[n];}
        }
        if (m==-1) break;
        else {
            for (auto p: roads[m]) {
                if (dist[m]+p.second<dist[p.first]) dist[p.first]=dist[m]+p.second;
            }
            vis[m]=true;
            check++;
        }
    }
}
int main() {
    scanf("%d%d", &N, &T);
    memset(dist, 0x3f, sizeof(dist));
    for (int t=0, x, y, c; t<T; t++) {
        scanf("%d%d%d", &x, &y, &c);
        roads[x].emplace_back(y, c);
        roads[y].emplace_back(x, c);
    }
    scanf("%d", &K);
    for (int k=0, x, p; k<K; k++) {
        scanf("%d%d", &x, &p);
        prices[x]=p;
    }
    scanf("%d", &D);
    dist[D]=0;
    Dijkstra();
    int cost=0x3f3f3f3f;
    for (int n=1; n<=N; n++) {
        if (prices[n]!=0&&dist[n]!=0x3f3f3f3f&&prices[n]+dist[n]<cost) cost=prices[n]+dist[n];
    }
    printf("%d", cost);
}
