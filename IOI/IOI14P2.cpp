#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e6+4;
void push_up(int i);
void build(int i, int l, int r);
void add(int i, int l, int r, int h);
void rem(int i, int l, int r, int h);
void push_down_h(int i);
void push_down_l(int i);
void upd(int i, int l, int r, int* finalHeight);
void buildWall(int N, int K, int op[], int left[], int right[], int height[], int finalHeight[]);
struct node{
    int l, r, high, low;
    bool lazyh, lazyl;
};
node st[3*MAXN];
void push_up(int i) {
    st[i].high=min(st[i<<1].high, st[i<<1|1].high);
    st[i].low=max(st[i<<1].low, st[i<<1|1].low);
}
void build(int i, int l, int r) {
    st[i]={l, r, 0, 0, 0, 0};
    if (l==r) {
        return;
    }
    int m=l+r>>1;
    build(i<<1, l, m);
    build(i<<1|1, m+1, r);
}
void add(int i, int l, int r, int h) {
    if (st[i].l>r||st[i].r<l||st[i].high>=h) return;
    if (st[i].l==l&&st[i].r==r) {
        st[i].high=h;
        st[i].lazyh=1;
        if (h>st[i].low) {
            st[i].low=h;
            st[i].lazyl=1;
        }
        return;
    }
    if (st[i].lazyh) push_down_h(i);
    if (st[i].lazyl) push_down_l(i);
    int m=st[i].l+st[i].r>>1;
    if (l>m) add(i<<1|1, l, r, h);
    else if (r<=m) add(i<<1, l, r, h);
    else {
        add(i<<1, l, m, h);
        add(i<<1|1, m+1, r, h);
    }
    push_up(i);
}
void rem(int i, int l, int r, int h) {
    if (st[i].l>r||st[i].r<l||st[i].low<=h) return;
    if (st[i].l==l&&st[i].r==r) {
        st[i].low=h;
        st[i].lazyl=1;
        if (h<st[i].high) {
            st[i].high=h;
            st[i].lazyh=1;
        }
        return;
    }
    if (st[i].lazyh) push_down_h(i);
    if (st[i].lazyl) push_down_l(i);
    int m=st[i].l+st[i].r>>1;
    if (l>m) rem(i<<1|1, l, r, h);
    else if (r<=m) rem(i<<1, l, r, h);
    else {
        rem(i<<1, l, m, h);
        rem(i<<1|1, m+1, r, h);
    }
    push_up(i);
}
void push_down_h(int i) {
    add(i<<1, st[i<<1].l, st[i<<1].r, st[i].high);
    add(i<<1|1, st[i<<1|1].l, st[i<<1|1].r, st[i].high);
    st[i].lazyh=0;
}
void push_down_l(int i) {
    rem(i<<1, st[i<<1].l, st[i<<1].r, st[i].low);
    rem(i<<1|1, st[i<<1|1].l, st[i<<1|1].r, st[i].low);
    st[i].lazyl=0;
}
void upd(int i, int* finalHeight) {
    if (st[i].l==st[i].r) {
        finalHeight[st[i].l]=st[i].low;
        return;
    }
    if (st[i].lazyh) push_down_h(i);
    if (st[i].lazyl) push_down_l(i);
    upd(i<<1, finalHeight);
    upd(i<<1|1, finalHeight);
}
void buildWall(int N, int K, int op[], int left[], int right[], int height[], int finalHeight[]) {
    build(1, 0, N-1);
    for (int n=0; n<K; n++) {
        if (op[n]==1) add(1, left[n], right[n], height[n]);
        else rem(1, left[n], right[n], height[n]);
    }
    upd(1, finalHeight);
}
/*int n, k, op[30], left[30], right[30], height[30], finalHeight[30];
int main() {
    scanf("%d%d", &n, &k);
    for (int i=0; i<k; i++) {
        scanf("%d%d%d%d", &op[i], &left[i], &right[i], &height[i]);
    }
    buildWall(n, k, op, left, right, height, finalHeight);
    for (int i=0; i<n; i++) printf("%d ", finalHeight[i]);
}
*/
