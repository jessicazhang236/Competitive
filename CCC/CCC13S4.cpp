#include <bits/stdc++.h>
using namespace std;
int N, M, p, q;
vector<int> adj[1000004];
bool vis[1000004];
void DFS(int cur, int src) {
    vis[cur]=true;
    for (int v: adj[cur]) {
        if (!vis[v])
            DFS(v, cur);
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for (int m=0, a, b; m<M; m++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
    }
    scanf("%d %d", &p, &q);
    DFS(p, p);
    if (vis[q])
        printf("yes");
    else {
        memset(vis, 0, sizeof(vis));
        DFS(q, q);
        if (vis[p])
            printf("no");
        else
            printf("unknown");
    }
}
