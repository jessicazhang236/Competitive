#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+4, M=1e9+7;
int N;
ll area, ans;
vector<int> pts;
unordered_map<int, int> cmprs;
struct node {
    int l, r;
    ll h;
    bool flg;
}st[MAXN*3];
struct book {
    int s, l, w;
};
vector<book> books;
void build (int i, int l, int r) {
    if (l==r) {
        st[i]={l, r, 0LL, 0};
        return;
    }
    int m=l+r>>1;
    build(i<<1, l, m);
    build(i<<1|1, m+1, r);
    st[i]={l, r, max(st[i<<1].h, st[i<<1|1].h), 0};
}
void push_down(int i) {
    if (!st[i].flg) return;
    if (st[i].l^st[i].r) {
        st[i<<1].h=st[i<<1|1].h=st[i].h;
        st[i<<1].flg=st[i<<1|1].flg=1;
    }
    st[i].flg=0;
}
void update (int i, int l, int r, int val) {
    if (l==st[i].l&&r==st[i].r) {
        st[i].h=val;
        st[i].flg=1;
        return;
    }
    push_down(i);
    int m=st[i].l+st[i].r>>1;
    if (r<=m) update(i<<1, l, r, val);
    else if (l>m) update(i<<1|1, l, r, val);
    else {
        update(i<<1, l, m, val);
        update(i<<1|1, m+1, r, val);
    }
    st[i].h=max(st[i<<1].h, st[i<<1|1].h);
}
ll query(int i, int l, int r) {
    if (l==st[i].l&&r==st[i].r) return st[i].h;
    push_down(i);
    int m=st[i].l+st[i].r>>1;
    if (r<=m) return query(i<<1, l, r);
    else if (l>m) return query(i<<1|1, l, r);
    else return max(query(i<<1, l, m), query(i<<1|1, m+1, r));
}
int main() {
    scanf("%d", &N);
    for (int n=0, s, l, w; n<N; n++) {
        scanf("%d%d%d", &s, &l, &w);
        area+=1LL*l*w;
        pts.push_back(s);
        pts.push_back(s+l);
        books.push_back({s, s+l, w});
    }
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    for (int i=0; i<pts.size(); i++) cmprs[pts[i]]=i;
    build(1, 1, pts.size());
    for (auto b: books) {
        update(1, cmprs[b.s]+1, cmprs[b.l], query(1, cmprs[b.s]+1, cmprs[b.l])+b.w);
    }
    for(int i=1;i<pts.size();i++) {
        ans+=1LL*query(1,i,i)*(pts[i]-pts[i-1]);
    }
    ans=ans-area;
    printf("%lld", ans%M);
}
