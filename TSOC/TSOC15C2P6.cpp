#include <bits/stdc++.h>
using namespace std;
const int MAXN=3e4+4;
int N, Q, R[MAXN];
struct node{
    int l, r, val, lz;
};
node st[MAXN*4];
void build(int l, int r, int i=1) {
    if (l!=r) {
        int m=l+r>>1;
        build(l, m, i<<1);
        build(m+1, r, i<<1|1);
        st[i]={l, r, min(st[i<<1].val, st[i<<1|1].val), 0};
    }
    else st[i]={l, r, R[l], 0};
}
void push_down(int i) {
    if (st[i].l!=st[i].r) {
        st[i<<1].val=max(st[i<<1].val-st[i].lz, 0);
        st[i<<1|1].val=max(st[i<<1|1].val-st[i].lz, 0);
        st[i<<1].lz+=st[i].lz;
        st[i<<1|1].lz+=st[i].lz;
        st[i].lz=0;
    }
}
void update(int l, int r, int val, int i=1) {
    if (st[i].lz) push_down(i);
    if (l==st[i].l&&r==st[i].r) {
        st[i].val=max(st[i].val-val, 0);
        st[i].lz+=val;
    }
    else {
        int m=st[i].l+st[i].r>>1;
        if (r<=m) update(l, r, val, i<<1);
        else if (l>m) update(l, r, val, i<<1|1);
        else {
            update(l, m, val, i<<1);
            update(m+1, r, val, i<<1|1);
        }
        st[i].val=min(st[i<<1].val, st[i<<1|1].val);
    }
}
int query(int l, int r, int i=1) {
    if (st[i].lz) push_down(i);
    if (l==st[i].l&&r==st[i].r) return st[i].val;
    else {
        int m=st[i].l+st[i].r>>1;
        if (r<=m) return query(l, r, i<<1);
        else if (l>m) return query(l, r, i<<1|1);
        else return min(query(l, m, i<<1), query(m+1, r, i<<1|1));
    }
}
int main() {
    scanf("%d%d", &N, &Q);
    for (int n=1; n<=N; n++) scanf("%d", &R[n]);
    build(1, N);
    for (int q=1, a, b, c; q<=Q; q++) {
        scanf("%d%d%d", &a, &b, &c);
        update(a, b, c);
        printf("%d %d\n", query(a, b), query(1, N));
    }
}
