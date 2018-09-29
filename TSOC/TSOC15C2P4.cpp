#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int MAXN=20004, mod=1000000007;
int N, M, ans, dist[MAXN], paths[MAXN], in[MAXN];
vector<int> adj[MAXN], D;
bool st[MAXN], ed[MAXN];
void DFS(int cur) {
    for (int i: adj[cur]) {
        paths[i]+=paths[cur];
        paths[i]%=mod;
        dist[i]=min(dist[i], dist[cur]+1);
        in[i]--;
        if (!in[i]) DFS(i);
    }
}
int main() {
    memset(dist, 0x3f, sizeof dist);
    scanf("%d%d", &N, &M);
    for (int m=1, a, b; m<=M; m++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        in[b]++;
        st[a]=true;
        ed[b]=true;
    }
    for (int n=0; n<N; n++) {
        if (!ed[n]) {
            dist[n]=1;
            paths[n]=1;
            DFS(n);
        }
    }
    for (int n=0; n<N; n++) {
        if (!st[n]) {
            ans=(ans+paths[n])%mod;
            D.push_back(dist[n]);
        }
    }
    printf("%d\n", ans);
    for (int d=0; d<D.size(); d++) printf("%d ", D[d]);
}
