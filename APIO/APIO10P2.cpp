#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+4;
int N, K, lp[MAXN], slp[MAXN], dia, par[MAXN], len, st, lst;
map<int, int> adj[MAXN];
void dfs1(int cur, int src, int d, int ind) {
    if (ind==2) par[cur]=src;
    if (d>len) {
        len=d;
        if (ind==1) st=cur;
        else lst=cur;
    }
    for (auto p: adj[cur]) {
        if (p.first!=src) dfs1(p.first, cur, d+1, ind);
    }
}
void dfs2(int cur, int src) {
    for (auto p: adj[cur]) {
        if (p.first!=src) {
            dfs2(p.first, cur);
            if (lp[p.first]+p.second>lp[cur]) {slp[cur]=lp[cur]; lp[cur]=lp[p.first]+p.second;}
            else if (lp[p.first]+p.second>slp[cur]) slp[cur]=lp[p.first]+p.second;
        }
    }
    dia=max(dia, lp[cur]+slp[cur]);
}
int main() {
    scanf("%d%d", &N, &K);
    for (int n=1, a, b; n<N; n++) {
        scanf("%d%d", &a, &b);
        adj[a][b]=1;
        adj[b][a]=1;
    }
    dfs1(1, -1, 0, 1);
    len=-1;
    dfs1(st, -1, 0, 2);
    if (K==1) printf("%d\n", 2*N-len-1);
    else {
        int cur=par[lst];
        while (cur!=-1) {
            adj[lst][cur]=adj[cur][lst]=-1;
            lst=cur, cur=par[cur];
        }
        dfs2(1, -1);
        printf("%d\n", 2*N-len-dia);
    }
}
