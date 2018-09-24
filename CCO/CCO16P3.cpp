#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+4;
typedef pair<int, int> pii;
int S, T, N, M, dfn[MAXN], deg[MAXN], l, vis[MAXN];
vector<int> adj[MAXN], loop;
set<pii> done;
bool used(int cur, int src) {
    if (cur>src) swap(cur, src);
    if (done.count({cur, src})) return true;
    done.insert({cur, src});
    return false;
}
bool check(int cur, int src) {
    // wander around the existing cycle and search degree
    int degree=0;
    if (deg[cur]>=3) degree++;
    int a=cur;
    int b=src;
    if (a>b) swap(a, b);
    if (used(a, b)) return true;
    for (int i=loop.size()-1; i>0; i--) {
        if (loop[i]==cur) break;
        int u=loop[i];
        int v=loop[i-1];
        if (deg[u]>=3) degree++;
        if (u>v) swap(u, v);
        if (S==5&&degree>=2) return true;
        if (S!=5&&used(u, v)) return true;
    }
    return false;
}
bool cycle(int cur, int src) {
    // 1 for current, 0 for not done, -1 for done
    dfn[cur]=dfn[src]+1;
    vis[cur]=1;
    loop.push_back(cur);
    bool flag=false;
    for (int a: adj[cur]) {
        if (a==src) continue;
        if (vis[a]==1) {
            l=max(l, dfn[cur]-dfn[a]+1);
            if (l>=4) return true;
            if (check(a, cur)) return true;
        }
        else if (vis[a]==0) flag|=cycle(a, cur);
    }
    vis[cur]=-1;
    loop.pop_back();
    return flag;
}
bool dfs(int cur, int src) {
    if (vis[cur]==1) return check(cur, src);
    bool flag=false;
    vis[cur]=1;
    loop.push_back(cur);
    for (int a: adj[cur]) {
         if (vis[a]>=0&&a!=src) flag|=dfs(a, cur);
    }
    vis[cur]=-1;
    loop.pop_back();
    return flag;
}
bool solve() {
    if (S==1) return dfs(1, 1);
    else if (S==2) {
        if (M>=N) return true;
        else return false;
    }
    else if (S==3) return cycle(1, 1);
    else if (S==4) {
        for (int n=1; n<=N; n++) {
            if (deg[n]>=3) return true;
        }
        return false;
    }
    else {
        if (N<5) return false;
        if (N==5) {
            for (int n=1; n<=N; n++) {
                if (deg[n]>=3) {
                    for (int a: adj[n]) {
                        if (deg[a]>=3) return true;
                    }
                }
            }
            return false;
        }
        return dfs(1, 0);
    }
}
int main() {
    scanf("%d%d", &S, &T);
    for (int t=1; t<=T; t++) {
        done.clear();
        loop.clear();
        for (int n=0; n<MAXN; n++) {
            adj[n].clear();
            vis[n]=0;
            deg[n]=0;
        }
        l=0;
        scanf("%d%d", &N, &M);
        for (int m=0, a, b; m<M; m++) {
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            deg[a]++;
            deg[b]++;
            adj[b].push_back(a);
        }
        if (solve()) printf("YES\n");
        else printf("NO\n");
    }
}
