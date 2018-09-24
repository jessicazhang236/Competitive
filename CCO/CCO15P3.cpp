#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN=2004;
const double e=0.0000001;
int X, K, N, Q;
ll c;
struct plane {
    int x, y;
    ll inf;
    plane(int a, int b, ll d) {
        x=a;
        y=b;
        inf=d;
    }
};
vector<plane> planes;
struct node {
    int l, r;
    ll Max;
};
node st[MAXN][6*MAXN];
vector<pair<double, ll>> sects[MAXN];
inline void push_up(int i, int pl) {
    st[pl][i].Max=max(st[pl][i<<1].Max, st[pl][i<<1|1].Max);
}
void build (int i, int l, int r, int pl) {
    st[pl][i].l=l;
    st[pl][i].r=r;
    if (l==r) {
        st[pl][i].Max=sects[pl][l].second;
        return;
    }
    int m=l+r>>1;
    build(i<<1, l, m, pl);
    build(i<<1|1, m+1, r, pl);
    push_up(i, pl);
}
ll query(int i, int l, int r, int pl) {
    if (l==st[pl][i].l&&r==st[pl][i].r) return st[pl][i].Max;
    int m=st[pl][i].l+st[pl][i].r>>1;
    if (r<=m) return query(i<<1, l, r, pl);
    else if (l>m) return query(i<<1|1, l, r, pl);
    else return max(query(i<<1, l, m, pl), query(i<<1|1, m+1, r, pl));
}
inline double intersect(int a1, int a2, int b1, int b2) {
    return 1.0*X*(double)(b1-a1)/(double)((a2-a1)-(b2-b1));
}
int main() {
    scanf("%d%d%d%d", &X, &K, &N, &Q);
    for (int n=1, a, b; n<=N; n++) {
        scanf("%d%d%lld", &a, &b, &c);
        planes.push_back(plane(a, b, c));
    }
    for (int n=0; n<N; n++) {
        for (int m=n+1; m<N; m++) {
            if (planes[n].x>planes[m].x&&planes[n].y>planes[m].y) {
                sects[m].emplace_back(0.0, planes[n].inf);
                continue;
            }
            if (planes[n].x<planes[m].x&&planes[n].y<planes[m].y) {
                sects[n].emplace_back(0.0, planes[m].inf);
                continue;
            }
            double a=intersect(planes[n].x, planes[n].y, planes[m].x, planes[m].y);
            if (planes[n].x<planes[m].x) {
                sects[n].emplace_back(0.0,planes[m].inf);
                sects[n].emplace_back(a-e,-planes[m].inf);
                sects[m].emplace_back(a+e,planes[n].inf);
            } else {
                sects[m].emplace_back(0.0,planes[n].inf);
                sects[m].emplace_back(a-e,-planes[n].inf);
                sects[n].emplace_back(a+e,planes[m].inf);
            }
        }
        sects[n].emplace_back(0.0, 0LL);
        sects[n].emplace_back((double)X, 0LL);
        sort(sects[n].begin(), sects[n].end());
        for (int m=1; m<sects[n].size(); m++) sects[n][m].second+=sects[n][m-1].second;
        build(1, 0, sects[n].size()-1, n);
    }
    for (int q=1, p, s; q<=Q; q++) {
        scanf("%d%d", &p, &s);
        p--;
        int l=max(1, (int)(upper_bound(sects[p].begin(), sects[p].end(), make_pair(1.0*s, 0LL))-sects[p].begin()))-1;
        int r=max(1, (int)(upper_bound(sects[p].begin(), sects[p].end(), make_pair(1.0*s+K, 0LL))-sects[p].begin()))-1;
        printf("%lld\n", query(1, l, r, p));
    }
}
