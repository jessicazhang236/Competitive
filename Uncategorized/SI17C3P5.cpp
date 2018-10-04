#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int MAXN=1e5+4;
int N, sz[MAXN]/*, freq[MAXN*2]*/;
unordered_map<int, int> freq;
ll ans;
bool done[MAXN];
vector<pii> adj[MAXN];
vector<int> vec;
char c;
void dfs(int u, int p) {
    sz[u]=1;
    for (auto m: adj[u]) {
        int v=m.first;
        if (v!=p&&!done[v]) {
            dfs(v, u);
            sz[u]+=sz[v];
        }
    }
}
int getCentre(int u, int p, int tot) {
    for (auto m: adj[u]) {
        int v=m.first;
        if (v!=p&&!done[v]&&sz[v]*2>tot) return getCentre(v, u, tot);
    }
    return u;
}
void getPath(int u, int par, int sum) {
    vec.push_back(sum);
    ans+=freq[1-sum]+freq[-1-sum];
    for (auto e: adj[u]) {
        if (done[e.first]||e.first==par) continue;
        getPath(e.first, u, sum+e.second);
    }
}
void solve(int rt) {
    dfs(rt, 0);
    rt=getCentre(rt, 0, sz[rt]);
    freq.clear();
    freq[0]=1;
    done[rt]=1;
    for (auto e: adj[rt]) {
        if (done[e.first]) continue;
        vec.clear();
        getPath(e.first, rt, e.second);
        for (int v: vec) freq[v]++;
    }
    for (auto e: adj[rt]) {
        if (!done[e.first]) solve(e.first);
    }
}
int main() {
    scanf("%d", &N);
    for (int n=1, a, b, w; n<N; n++) {
        scanf("%d %d %c", &a, &b, &c);
        w=(c=='r')?1:-1;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
    solve(1);
    printf("%lld", ans-(N-1));
}
