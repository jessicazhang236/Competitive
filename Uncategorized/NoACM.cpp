#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN=304;
int T, N, K, ind[MAXN];
long double num, ncr[MAXN][MAXN];
vector<int> adj[MAXN];
set<int> vis;
pii path[MAXN][MAXN];
void init(){
    for (int n=1; n<=N; n++) {
        adj[n].clear();
        for (int i=1; i<=N; i++) {
            path[n][i].first=0;
            path[n][i].second=0;
        }
    }
    memset(ind, 0, sizeof ind);
    num=0;
}
void dfs(int rt, int cur, int src, int dist) {
    bool flg=0;
    if (!vis.count(ind[cur])) {
        vis.insert(ind[cur]);
        flg=1;
    }
    path[rt][cur].first=vis.size(), path[rt][cur].second=dist;
    for (int a: adj[cur]) {
        if (a==src) continue;
        dfs(rt, a, cur, dist+1);
    }
    if (flg) vis.erase(ind[cur]);
}
int main() {
    for (int n=0; n<MAXN; n++) {
        ncr[n][0]=ncr[n][n]=1;
        for (int i=1; i<n; i++) ncr[n][i]=ncr[n-1][i-1]+ncr[n-1][i];
    }
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        init();
        scanf("%d%d", &N, &K);
        K-=2;
        for (int n=1, a, b; n<N; n++) {
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int n=1; n<=N; n++) scanf("%d", &ind[n]);
        for (int n=1; n<=N; n++) dfs(n, n, -1, 0);
        for (int n=1; n<=N; n++) {
            for (int i=n+1; i<=N; i++) {
                int dist=path[n][i].second;
                int cnt=0;
                for (int j=1; j<=N; j++) {
                    if (j==n||j==i) continue;
                    if (path[n][j].second>dist||path[i][j].second>dist) continue;
                    if (path[n][j].second==dist&&j<i) continue;
                    if (path[i][j].second==dist&&j<n) continue;
                    cnt++;
                }
                if (cnt>=K) num+=path[n][i].first*ncr[cnt][K];
            }
        }
        printf("%.6llf\n", num/ncr[N][K+2]);
    }
}
