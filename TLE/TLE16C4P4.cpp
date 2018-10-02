#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int MAXN=100004;
int N, M, Q, end1, end2, Time[MAXN], par[MAXN];
ll ans=0LL, max_d;
vector<pii> adj[MAXN];
bool vis[MAXN];
priority_queue<ll> d;
void dfs1 (int cur, int src, ll dis) {
    vis[cur]=true;
    if (dis>max_d) {max_d=dis; end1=cur;}
    for (auto p: adj[cur]) {
        int i=p.first;
        if (i!=src&&!vis[i]) dfs1(i, cur, dis+p.second);
    }
}
void dfs2 (int cur, int src, ll dis) {
    if (dis>max_d) {max_d=dis; end2=cur;}
    for (auto p: adj[cur]) {
        int i=p.first;
        if (i!=src) {
            par[i]=cur;
            Time[i]=p.second;
            dfs2(i, cur, dis+p.second);
        }
    }
}
int main () {
    scanf("%d%d%d", &N, &M, &Q);
    for (int m=1, a, b, c; m<=M; m++) {
        scanf("%d%d%d", &a, &b, &c);
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    for (int n=1; n<=N; n++) {
        if (!vis[n]) {
            max_d=-1;
            dfs1(n, -1, 0LL);
            max_d=-1;
            par[end1]=-1LL;
            dfs2(end1, -1, 0);
            if (Q==1) ans+=max_d+1;
            else {
                ll R=0x3f3f3f3f3f3f3f3f, r=0LL;
                for (int i=end2; i>0; i=par[i]) {
                    r+=Time[i];
                    R=min(R, max(r, max_d-r));
                }
                d.push(R);
            }
        }
    }
    if (Q==1) printf("%lld", ans-1LL);
    else {
        ans=d.top();
       // printf("%d\n", ans);
        d.pop();
        if (d.empty()) printf("%lld", ans);
        else {
            ll sec=d.top();
          //  printf("%d\n", sec);
            if (ans>sec) printf("%lld", ans);
            else printf("%lld", ans+1LL);
        }
    }
}
