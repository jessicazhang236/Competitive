#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+4;
int N, Q;
ll num[MAXN];
char cmd;
struct node{
    int l, r;
    ll pre, suf, sum, tot;
    node(){l=r=0;pre=suf=sum=tot=0;}
    node(int a, int b, ll c, ll d, ll e, ll f){l=a; r=b; pre=c; suf=d; sum=e; tot=f;}
}st[MAXN*3];
node best(node l, node r) {
    node m=node(l.l, r.r, max(l.pre, l.tot+r.pre), max(r.suf, r.tot+l.suf), max(max(l.sum, r.sum), l.suf+r.pre), l.tot+r.tot);
    m.sum=max(max(m.pre, m.suf), max(m.sum, m.tot));
    return m;
}
void push_up(int i) {
    st[i]=best(st[i<<1], st[i<<1|1]);
}
void build (int i, int l, int r) {
    if (l==r) {
        st[i]={l, r, num[l], num[r], num[l], num[r]};
        return;
    }
    int m=l+r>>1;
    build(i<<1, l, m);
    build(i<<1|1, m+1, r);
    push_up(i);
}
void update (int i, int u, ll val) {
    if (st[i].l==st[i].r) {
        st[i].tot=val;
        st[i].sum=val;
        st[i].pre=val;
        st[i].suf=val;
        return;
    }
    int m=st[i].l+st[i].r>>1;
    if (u<=m) update(i<<1, u, val);
    else update(i<<1|1, u, val);
    push_up(i);
}
node query(int i, int l, int r) {
    if (l==st[i].l&&r==st[i].r) return st[i];
    int m=st[i].l+st[i].r>>1;
    if (r<=m) return query(i<<1, l, r);
    else if (l>m) return query(i<<1|1, l, r);
    else return best(query(i<<1, l, m), query(i<<1|1, m+1, r));
}
int main() {
    scanf("%d%d", &N, &Q);
    for (int n=1; n<=N; n++) scanf("%lld", &num[n]);
    build(1, 1, N);
    for(int q=0, x, y; q<Q; q++) {
        scanf(" %c%d%d", &cmd, &x, &y);
        if(cmd=='S') update(1, x, y);
        else printf("%lld\n", query(1, x, y).sum);
    }
}
