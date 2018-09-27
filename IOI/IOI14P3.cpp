#include <bits/stdc++.h>
using namespace std;
const int MAXN=1504;
int ds[MAXN], sz[MAXN], cnt[MAXN];
void initialize(int n) {
    for (int i=0; i<n; i++) {
        ds[i]=i;
        sz[i]=1;
        cnt[i]=n-1;
    }
}
inline int findRoot(int i) {
    if (ds[i]!=i) ds[i]=findRoot(ds[i]);
    return ds[i];
}
inline void Merge(int i, int j) {
    ds[i]=j;
    sz[j]+=sz[i];
    cnt[j]-=sz[i];
}
int hasEdge(int u, int v) {
    u=findRoot(u), v=findRoot(v);
    if (u==v) return 0;
    else if (cnt[u]==1||cnt[v]==1) {
        Merge(u, v);
        return 1;
    }
    else {
        cnt[u]--;
        cnt[v]--;
        return 0;
    }
}
