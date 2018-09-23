#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
const int MAXN=2004;
typedef pair<int, int> pii;
typedef tuple<int, int, int> trio;
int K, N, M, A, B, dist[MAXN][204];
bool vis[MAXN];
vector<trio> adj[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> Queue;
inline void update() {
    memset(dist, 0x3f, sizeof dist);
    Queue.push({0, A});
    dist[A][0]=0;
    vis[A]=true;
	while (!Queue.empty()) {
		pii a=Queue.top();
        int m=a.second;
		Queue.pop();
		for (int i=0; i<adj[m].size(); i++) {
            trio t=adj[m][i];
            for (int j=0; j+get<2>(t)<K; j++) {
                int fast=dist[m][j]+get<1>(t);
                if (fast<dist[get<0>(t)][j+get<2>(t)]) {
                    dist[get<0>(t)][j+get<2>(t)]=fast;
                    if (!vis[get<0>(t)]) {
                        vis[get<0>(t)]=true;
                        Queue.push({fast, get<0>(t)});
                    }
                }
            }
		}
		vis[m]=false;
	}
}
int main() {
    scanf("%d%d%d", &K, &N, &M);
    for (int m=1, a, b, t, h; m<=M; m++) {
        scanf("%d%d%d%d", &a, &b, &t, &h);
        adj[a].emplace_back(b, t, h);
        adj[b].emplace_back(a, t, h);
    }
    scanf("%d%d", &A, &B);
    update();
    int ans=0x3f3f3f3f;
    for (int k=0; k<K; k++) ans=min(ans, dist[B][k]);
    if (ans==0x3f3f3f3f) printf("-1");
    else printf("%d", ans);
}
