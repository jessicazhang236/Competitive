#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN=1e5+4;
int N, ord[MAXN], rt[MAXN], val[MAXN], sz[MAXN];
map<int, int> cnt[MAXN];
ll ans[MAXN];
vector<pii> adj[MAXN], edge;
int fnd(int x) {
    if (rt[x]!=x) rt[x]=fnd(rt[x]);
    return rt[x];
}
void mrg(int a, int b) {
    rt[a]=b;
    sz[b]+=sz[a];
}
void dfs (int cur, int src) {
    cnt[cur][val[cur]]=1;
    for (auto u: adj[cur]) {
        if (u.first==src) continue;
        val[u.first]=val[cur]^u.second;
        dfs(u.first, cur);
    }
}
int main() {
    scanf("%d", &N);
    for (int n=1, a, b, z; n<N; n++) {
        scanf("%d%d%d", &a, &b, &z);
        adj[a].emplace_back(b, z);
        adj[b].emplace_back(a, z);
        edge.emplace_back(a, b);
        rt[n]=n;
        sz[n]=1;
    }
    rt[N]=N;
    sz[N]=1;
    dfs(1, -1);
    for (int n=1; n<N; n++) {
        scanf("%d", &ord[n]);
        ord[n]--;
    }
    for (int n=N-1; n>=1; n--) {
        ans[n]+=ans[n+1];
        int u=edge[ord[n]].first;
        int v=edge[ord[n]].second;
        u=fnd(u);
        v=fnd(v);
        if (sz[u]>sz[v]) swap(u, v);
        mrg(u, v);
        for (auto num: cnt[u]) {
            if (cnt[v].count(num.first)) {
                ans[n]+=1LL*cnt[v][num.first]*num.second;
                cnt[v][num.first]+=num.second;
            }
            else cnt[v].insert(num);
        }
    }
    for (int n=1; n<=N; n++) printf("%lld\n", ans[n]);
}
