#include <bits/stdc++.h>
using namespace std;
const int MAX=1000004;
int N, M, K, l, id[MAX], sz[MAX], ans, cut;
bool cycle[MAX], vis[MAX];
int findRoot (int x) {
    if (x!=id[x])
        id[x]=findRoot(id[x]);
    return id[x];
}
void mergeSet(int x, int y) {
    id[findRoot(x)]=findRoot(y);
}
int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int n=1; n<=N; n++) {id[n]=n; sz[n]=1;}
    for (int m=1, a, b; m<=M; m++) {
        scanf("%d%d", &a, &b);
        if (findRoot(a)!=findRoot(b)) {
            int m=sz[findRoot(a)]+sz[findRoot(b)];
            mergeSet(a, b);
            sz[findRoot(a)]=m;
        }
        else cycle[findRoot(a)]=true;
    }
    for (int i=1; i<=N; i++) {
        int n=findRoot(i);
        if (vis[n]) continue;
        if (sz[n]<K) continue;
        ans+=sz[n]/K;
        cut+=sz[n]/K;
        if (!(sz[n]%K)) cut--;
        if (cycle[n]&&(sz[n]!=K)) cut++;
        vis[n]=true;
    }
    printf("%d %d", ans*K, cut);
}
