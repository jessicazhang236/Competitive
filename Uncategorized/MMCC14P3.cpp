#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN=5004;
int N, S, L, R, l, i, r, par[MAXN];
vector<int> adj[MAXN], ord;
queue<int> q;
queue<pii> Q;
bool vis[MAXN], cov[MAXN];
int bfs(int src) {
    q.push(src);
    vis[src]=1;
    while (!q.empty()) {
        i=q.front();
        q.pop();
        for (int j: adj[i]) {
            if (!vis[j]) q.push(j);
            vis[j]=1;
        }
    }
    return i;
}
int main() {
    //freopen("C:\\Users\\zhanghao\\Downloads\\esdeath\\esdeath.1.in", "r", stdin);
    scanf("%d%d", &N, &S);
    for (int n=1, i, j; n<N; n++) {
        scanf("%d%d", &i, &j);
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    L=bfs(1);
    memset(vis, 0, sizeof vis);
    q.push(L);
    par[L]=L;
    vis[L]=1;
    while (!q.empty()) {
        i=q.front();
        q.pop();
        ord.push_back(i);
        for (int j: adj[i]) {
            if (vis[j]) continue;
            par[j]=i;
            vis[j]=1;
            q.push(j);
        }
    }
    memset(vis, 0, sizeof vis);
    R=i;
    r=N;
    while (l<=r) {
        memset(cov, 0, sizeof cov);
        int m=l+r>>1;
        int cnt=0;
        for (int u=ord.size()-1; u>=0; u--) {
            int v=ord[u];
            if (cov[v]) continue;
            for (int c=1; c<=m; c++) v=par[v];
            cnt++;
            Q.push({v, 0});
            vis[v]=1;
            while (!Q.empty()) {
                pii a=Q.front();
                Q.pop();
                if (a.second>m) break;
                cov[a.first]=1;
                for (int b: adj[a.first]) {
                    if (!vis[b]) Q.push({b, a.second+1});
                    vis[b]=1;
                }
            }
            while (!Q.empty()) Q.pop();
            memset(vis, 0, sizeof vis);
        }
        if (cnt>S) l=m+1;
        else r=m-1;
        cnt=0;
    }
    printf("%d\n", l);
}
