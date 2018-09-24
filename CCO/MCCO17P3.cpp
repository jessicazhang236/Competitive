#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
struct qu{
    int l, r, i;
};
const int MAXN=150004;
int N, D, Q, dist[MAXN], par[MAXN], rt[MAXN], block[MAXN];
vector<int> adj[MAXN];
pii ord[MAXN], ans[MAXN], qry[MAXN];
bool check;
queue<qu> query[MAXN];
void init(int a) {
    for (int n=1; n<=a; n++) rt[n]=block[n]=n;
}
void dfs(int cur, int src, int d) {
    par[cur]=src;
    dist[cur]=d;
    for (int i: adj[cur]) {
        if (i==src) continue;
        dfs(i, cur, d+1);
    }
}
int fnd(int n) {
    if (rt[n]!=n) rt[n]=fnd(rt[n]);
    return rt[n];
}
void mrg(int a, int b) {
    a=fnd(a);
    b=fnd(b);
    rt[a]=b;
}
int scc(int n) {
    if (block[n]!=n) block[n]=scc(block[n]);
    return block[n];
}
int lca(int a, int b) {
    while (scc(a)!=scc(b)) {
        if (dist[block[b]]>dist[block[a]]) swap(a, b);
        a=par[block[a]];
    }
    return scc(a);
}
void mrge(int a, int b) {
    int l=lca(a, b);
    while (scc(a)!=scc(b)) {
        if (dist[block[b]]>dist[block[a]]) swap(a, b);
        int x=scc(a);
        a=par[block[x]];
        block[x]=l;
    }
}
int main() {
    scanf("%d%d%d", &N, &D, &Q);
    init(N);
    for (int d=1, a, b; d<=D; d++) {
        scanf("%d%d", &a, &b);
        a++;
        b++;
        if (fnd(a)!=fnd(b)) {
            mrg(a, b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ord[d]=make_pair(a, b);
    }
    for (int n=1; n<=N; n++) {
        if (!par[n]) dfs(n, -1, 1);
    }
    for (int q=1, x, y; q<=Q; q++) {
        scanf("%d%d", &x, &y);
        x++;
        y++;
        qry[q]=make_pair(x, y);
        ans[q]=make_pair(1, D+1);
    }
    while (!check) {
        check=1;
        for (int q=1; q<=Q; q++) {
            if (ans[q].first!=ans[q].second) {
                check=0;
                int m=(ans[q].first+ans[q].second)/2;
                qu cur={qry[q].first, qry[q].second, q};
                query[m].push(cur);
            }
        }
        init(N);
        for (int d=1; d<=D; d++) {
            int a=ord[d].first;
            int b=ord[d].second;
            if (fnd(a)!=fnd(b)) mrg(a, b);
            else mrge(a, b);
            while (!query[d].empty()) {
                qu cur=query[d].front();
                query[d].pop();
                if (scc(cur.l)==scc(cur.r)) ans[cur.i].second=(ans[cur.i].first+ans[cur.i].second)/2;
                else ans[cur.i].first=(ans[cur.i].first+ans[cur.i].second)/2+1;
            }
        }
    }
    for (int q=1; q<=Q; q++) {
        int a=ans[q].first-1;
        if (a==D) printf("-1\n");
        else printf("%d\n", a);
    }
}
