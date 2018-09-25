#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+4;
struct node {
    int l, r, sum, lz;
};
int M, N, Q, elements[MAXN];
node st[MAXN*3];
void build (int i, int l, int r) {
    if (l==r) {
        st[i]={l, r, elements[r]%M, 0};
        return;
    }
    int m=l+r>>1;
    build(i<<1, l, m);
    build(i<<1|1, m+1, r);
    st[i]={l, r, (st[i<<1].sum%M+st[i<<1|1].sum%M)%M, 0};
}
inline void push_down(int i) {
    if (st[i].l^st[i].r) {
        st[i<<1].sum=(st[i<<1].sum%M+st[i].lz*(st[i<<1].r-st[i<<1].l+1)%M)%M;
        st[i<<1|1].sum=(st[i<<1|1].sum%M+st[i].lz*(st[i<<1|1].r-st[i<<1|1].l+1)%M)%M;
        st[i<<1].lz=(st[i<<1].lz%M+st[i].lz%M)%M;
        st[i<<1|1].lz=(st[i<<1|1].lz%M+st[i].lz%M)%M;
    }
    st[i].lz=0;
}
void update (int i, int l, int r, int val) {
    if (l==st[i].l&&r==st[i].r) {
        st[i].sum=(st[i].sum%M+val*(st[i].r-st[i].l+1)%M)%M;
        st[i].lz=(st[i].lz+val)%M;
        return;
    }
    if (st[i].lz) push_down(i);
    int m=st[i].l+st[i].r>>1;
    if (r<=m) update(i<<1, l, r, val);
    else if (l>m) update(i<<1|1, l, r, val);
    else {
        update(i<<1, l, m, val);
        update(i<<1|1, m+1, r, val);
    }
    st[i].sum=(st[i<<1].sum%M+st[i<<1|1].sum)%M;
}
inline int query(int i, int l, int r) {
    if (l==st[i].l&&r==st[i].r) return st[i].sum%M;
    if (st[i].lz) push_down(i);
    int m=st[i].l+st[i].r>>1;
    if (r<=m) return query(i<<1, l, r)%M;
    else if (l>m) return query(i<<1|1, l, r)%M;
    else return (query(i<<1, l, m)%M+query(i<<1|1, m+1, r)%M)%M;
}
int main() {
    scanf("%d%d%d", &M, &N, &Q);
    for (int n=1; n<=N; n++)
        scanf("%d", &elements[n]);
    build (1, 1, N);
    for (int q=0, cmd, l, r; q<Q; q++) {
        scanf("%d%d%d", &cmd, &l, &r);
        if (cmd==1) {
            int x;
            scanf("%d", &x);
            x%=M;
            update(1, l, r, x);
        }
        else {
            printf("%d\n", query(1, l, r));
        }
    }
}
