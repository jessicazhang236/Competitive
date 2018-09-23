#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+4;
int N, Q, ans[MAXN];
vector<int> adj[MAXN], loop[MAXN];
unordered_set<int> vis[MAXN];
unordered_map<int, int> ord[MAXN];
inline void dfs(int cur, int src) {
    unordered_set<int> edit;
    int cnt=0, u=cur, v=src;
    for (int i=0; i==0||u!=cur||v!=src; i++) {
        edit.insert(u);
        vis[u].insert(v);
        loop[u].push_back(i);
        cnt++;
        int tmp=ord[v][u]%adj[v].size();
        u=v;
        v=adj[u][tmp];
    }
    for (int j: edit) {
        for (int k=0; k<loop[j].size()-1; k++) ans[j]=max(ans[j], loop[j][k+1]-loop[j][k]);
        ans[j]=max(ans[j], loop[j][0]-loop[j].back()+cnt);
        loop[j].clear();
    }
}
int main() {
    scanf("%d", &N);
    for (int n=1, k; n<=N; n++) {
        scanf("%d", &k);
        for (int i=1, a; i<=k; i++) {
            scanf("%d", &a);
            adj[n].push_back(a);
            ord[n][a]=i;
        }
    }
    for (int n=1; n<=N; n++) {
        for (int a: adj[n]) {
            if (!vis[n].count(a)) dfs(n, a);
        }
    }
    scanf("%d", &Q);
    for (int q=1, a; q<=Q; q++) {
        scanf("%d", &a);
        printf("%d\n", ans[a]);
    }
}
