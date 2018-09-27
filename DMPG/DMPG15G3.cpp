#include <bits/stdc++.h>
using namespace std;
#define k first
#define c second
const int MAXN=200004;
typedef long long ll;
typedef pair<int, int> pii;
int N, LK, RK, LC, RC, sz[MAXN], bread[MAXN];
char c;
ll bit[MAXN];
bool done[MAXN];
vector<int> adj[MAXN];
vector<pii> cnt;
int dfs(int src, int par) {
    sz[src]=1;
    for (int v: adj[src]) {
        if (v!=par&&!done[v]) sz[src]+=dfs(v, src);
    }
    return sz[src];
}
void dfs2(int src, int par, int k, int c) {
    k+=bread[src]%2;
    c+=bread[src]/2;
    cnt.emplace_back(k, c);
    for (int v: adj[src]) {
        if (v!=par&&!done[v]) dfs2(v, src, k, c);
    }
}
void upd(int i, ll val) {
    i++;
    for (; i<MAXN; i+=i&-i) bit[i]+=val;
}
ll qry(int i) {
    i++;
    ll ans=0LL;
    for (; i>0; i-=i&-i) ans+=bit[i];
    return ans;
}
int getCentre(int src, int par, int tot) {
    for (int v: adj[src]) {
        if (v!=par&&!done[v]&&sz[v]*2>tot) return getCentre(v, src, tot);
    }
    return src;
}
ll query(int k, int c) {
    if (k<0||c<0) return 0;
    ll ans=0LL;
    int l=0;
    for (int r=cnt.size()-1; r>=0; r--) {
        if (cnt[r].k*2<=k&&cnt[r].c*2<=c) ans--;
        while (l<cnt.size()&&cnt[l].k+cnt[r].k<=k) {
            upd(cnt[l].c, 1);
            l++;
        }
        ans+=qry(c-cnt[r].c);
    }
    for (int i=0; i<l; i++) upd(cnt[i].c, -1);
    return ans;
}
ll calc(int src, int par, int lk, int rk, int lc, int rc) {
    ll ans=0LL;
    if (lk<=0&&rk>=0&&lc<=0&&rc>=0) ans+=2;
    vector<pii> tmp;
    tmp.emplace_back(0, 0);
    for (int v: adj[src]) {
        if (v!=par&&!done[v]) {
            cnt.clear();
            dfs2(v, v, 0, 0);
            sort(cnt.begin(), cnt.end());
            ans-=query(lk-1, lc-1)+query(rk, rc);
            ans+=query(rk, lc-1)+query(lk-1, rc);
            tmp.insert(tmp.end(), cnt.begin(), cnt.end());
        }
    }
    cnt=tmp;
    sort(cnt.begin(), cnt.end());
    ans+=query(lk-1, lc-1)+query(rk, rc);
    ans-=query(rk, lc-1)+query(lk-1, rc);
    return ans;
}
ll solve(int src) {
    ll ans=0LL;
    src=getCentre(src, src, dfs(src, src));
    done[src]=1;
    ans+=calc(src, src, LK-bread[src]%2, RK-bread[src]%2, LC-bread[src]/2, RC-bread[src]/2);
    for (int a: adj[src]) {
        if (!done[a]) ans+=solve(a);
    }
    return ans;
}
int main() {
    scanf("%d%d%d%d%d", &N, &LK, &RK, &LC, &RC);
    for (int n=1; n<=N; n++) {
        scanf(" %c", &c);
        if (c=='K') bread[n]=1;
        else bread[n]=2;
    }
    for (int n=1, a, b; n<N; n++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    printf("%lld", solve(1)/2);
}
