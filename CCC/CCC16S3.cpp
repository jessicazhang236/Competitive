#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef pair<int, int> pii;
const int MAXN=1e5+4;
int N, M, dist[2][MAXN], st, num, Max, cnt, cpho[MAXN], lst;
bool pho[MAXN], off[MAXN];
vector<int> adj[MAXN], adj2[MAXN];
vector<pii> road;
void prune(int cur, int src) {
    for (int i: adj[cur]) {
        if (i==src) continue;
        prune(i, cur);
        cpho[cur]+=cpho[i];
    }
    if (!cpho[cur]) off[cur]=1;
}
void dfs(int cur, int src, int ind) {
    for (int i: adj2[cur]) {
        if (i==src) continue;
        dist[ind][i]=dist[ind][cur]+1;
        if (dist[ind][i]>Max) {Max=dist[ind][i]; st=i;}
        dfs(i, cur, ind);
    }
}
int main() {
    scanf("%d%d", &N, &M);
    for (int m=1, a; m<=M; m++) {
        scanf("%d", &a);
        pho[a]=1;
        cpho[a]=1;
        lst=a;
    }
    for (int n=1, a, b; n<N; n++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
        road.pb({a, b});
    }
    prune(lst, lst);
    for (int n=0; n<N-1; n++) {
        pii p=road[n];
        int a=p.first, b=p.second;
        if (off[a]||off[b]) continue;
        adj2[a].pb(b);
        adj2[b].pb(a);
        num=a;
    }
    for (int n=0; n<N; n++) {
        if (adj2[n].size()) {
            cnt++;
            //printf("%d\n", n);
        }
    }
    dfs(num, num, 0);
    Max=0;
    dfs(st, st, 1);
    printf("%d\n", 2*(cnt-1)-Max);
}
