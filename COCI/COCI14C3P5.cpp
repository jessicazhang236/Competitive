#include <bits/stdc++.h>
using namespace std;
const int MAXN=3e5+4;
struct trio {
    bool type;
    int u, t;
    trio(bool a, int b, int c) {
        type=a;
        u=b;
        t=c;
    }
};
int N, v, w, top[MAXN], par[MAXN], LCA[20][MAXN], depth[MAXN];
char cmd;
vector<int> adj[MAXN];
vector<trio> ans;
void DFS(int cur, int src, int d=0) {
    LCA[0][cur]=src;
    depth[cur]=d;
    for (int i: adj[cur]) {
        if (i==src) continue;
        DFS(i,cur,d+1);
    }
}
void build() {
    for (int i=1; i<=19; i++) {
        for (int n=1; n<=N; n++) {
            LCA[i][n]=LCA[i-1][LCA[i-1][n]];
        }
    }
}
int query(int a, int b) {
    if (depth[a]<depth[b]) swap(a, b);
    for (int i=19; i>=0; i--) {
        if (depth[b]<=depth[LCA[i][a]])
            a=LCA[i][a];
    }
    if (a==b) return a;
    for (int i=19; i>=0; i--) {
        if (LCA[i][a]!=LCA[i][b]) {
            a=LCA[i][a];
            b=LCA[i][b];
        }
    }
    return LCA[0][a];
}
/*
int par[MAXN], jpar[MAXN];
void DFS(int cur, int src, int d=0) {
    par[cur]=src;
    depth[cur]=d;
    if (!d%RN) jpar[cur]=src;
    else jpar[cur]=jpar[src];
    for (int i: adj[cur]) {
        if (i==src) continue;
        DFS(i, cur, d+1);
    }
}
int find_LCA(int a, int b) {
    while (jpar[a]!=jpar[b]) {
        if (depth[a]<depth[b]) swap(a, b);
        a=jpar[a]];
    }
    while (a!=b) {
        if (depth[a]<depth[b]) swap(a, b);
        a=par[a];
    }
    return a;
}
*/
int main() {
    scanf("%d", &N);
    for (int n=1; n<=N; n++) {
        scanf(" %c", &cmd);
        if (cmd=='a') {
            scanf(" %d", &v);
            adj[top[v]].push_back(n);
            par[n]=top[v];
            top[n]=n;
        }
        else if (cmd=='b') {
            scanf(" %d", &v);
            ans.push_back(trio(false, top[v], 36));
            adj[par[top[v]]].push_back(n);
            top[n]=par[top[v]];
        }
        else {
            scanf(" %d%d", &v, &w);
            top[n]=top[v];
            adj[par[top[v]]].push_back(n);
            ans.push_back(trio(true, top[v], top[w]));
        }
    }
    DFS(0, -1);
    build();
    for (auto a: ans) {
        if (!a.type) printf("%d\n", a.u);
        else printf("%d\n", depth[query(a.u, a.t)]);
    }
}
