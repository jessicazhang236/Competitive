#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN=1004;
int N, R, c, cnt, low[MAXN], dfn[MAXN], bcc[MAXN], ans;
vector<pii> adj[MAXN], road;
vector<int> adj2[MAXN];
bool bridge[MAXN], vis[MAXN];
void Tarjan(int cur, int src) {
    dfn[cur]=low[cur]=++cnt;
    for (pii p: adj[cur]) {
        if (p.first==src) continue;
        int a=p.first;
        int b=p.second;
        if (!dfn[a]) {
            Tarjan(a, cur);
            low[cur]=min(low[cur], low[a]);
            if (low[a]>dfn[cur]) bridge[b]=1;
        }
        else low[cur]=min(low[cur], dfn[a]);
    }
}
void meld(int src, int i) {
    bcc[src]=i;
    for (pii p: adj[src]) {
        int a=p.first;
        int b=p.second;
        if (bcc[a]||bridge[b]) continue;
        meld(a, i);
    }
}
int main() {
    scanf("%d%d", &N, &R);
    for (int r=1, i, j; r<=R; r++) {
        scanf("%d%d", &i, &j);
        adj[i].emplace_back(j, r);
        adj[j].emplace_back(i, r);
        road.emplace_back(i, j);
    }
    for (int n=1; n<=N; n++) {
        if (!dfn[n]) Tarjan(n, n);
    }
    for (int n=1; n<=N; n++) {
        if (!bcc[n]) meld(n, ++c);
    }
    for (int r=0; r<R; r++) {
        for (pii m: road) {
            int p=bcc[m.first];
            int q=bcc[m.second];
            if (p==q) continue;
            adj2[p].push_back(q);
            adj2[q].push_back(p);
        }
    }
    for (int i=1; i<=c; i++) {
        sort(adj2[i].begin(), adj2[i].end());
        adj2[i].erase(unique(adj2[i].begin(), adj2[i].end()),adj2[i].end());
        if (adj2[i].size()==1) ans++;
    }
    printf("%d", ans+1>>1);
}
