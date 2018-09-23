#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, Q, mi, xi, ai, bi, wi, root[1004], ans[100004];
pii edges[5004];
vector<pii> val;
struct trio{
    int f, s, t, ind;
    trio(int a, int b, int c, int d) {
        f=a, s=b, t=c, ind=d;
    }
};
vector<trio> queries, group;
inline int fnd(int m) {
    if (root[m]!=m) root[m]=fnd(root[m]);
    return root[m];
}
inline void mrg(int m, int n) {root[fnd(m)]=fnd(n);}
void init() {
    for (int n=1; n<=N; n++) {
        root[n]=n;
    }
}
inline void update(int a, int b) {
    for (pii &p: val) {
        if (p.second==a) {
            p.first=b;
            break;
        }
   }
}
bool cmp(trio a, trio b) {
    return a.t>b.t;
}
void query() {
    init();
    sort(group.begin(), group.end(), cmp);
    sort(val.begin(), val.end(), greater<pii>());
    for (int m=0, l=0, i, u, v; l<group.size(); l++) {
        while (m<M&&group[l].t<=val[m].first) {
            i=val[m].second;
            u=edges[i].first, v=edges[i].second;
            if (fnd(u)!=fnd(v)) mrg(u, v);
            m++;
        }
        if (fnd(group[l].f)==fnd(group[l].s)) ans[group[l].ind]=1;
        else ans[group[l].ind]=0;
    }
}
int main() {
    scanf("%d%d", &N, &M);
    for (int m=1, a, b, c; m<=M; m++) {
        scanf("%d%d%d", &a, &b, &c);
        edges[m]={a, b};
        val.emplace_back(c, m);
    }
    memset(ans, -1, sizeof ans);
    scanf("%d", &Q);
    for (int q=1, cmd; q<=Q; q++) {
        scanf("%d", &cmd);
        if (cmd==1) {
            query();
            group.clear();
            scanf("%d%d", &mi, &xi);
            update(mi, xi);
        }
        else {
            scanf("%d%d%d", &ai, &bi, &wi);
            group.push_back(trio(ai, bi, wi, q));
        }
    }
    if (group.size()) query();
    for (int q=1; q<=Q; q++) {
        if (ans[q]!=-1) printf("%d\n", ans[q]);
    }
}
