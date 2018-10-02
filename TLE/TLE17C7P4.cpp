#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200004, seed=31;
ll pw[MAXN];
int N, Q, L, cnt=1, root[MAXN];
struct node {
    int l, r;
    ll hsh;
    char c;
};
node st[MAXN*30];
char S[MAXN], ch;
void build (int &rt, int l, int r) {
    rt=cnt++;
    if (l==r) {
        st[rt].c=S[l];
        st[rt].hsh=S[l];
        return;
    }
    int m=l+r>>1;
    build(st[rt].l, l, m);
    build(st[rt].r, m+1, r);
    st[rt].hsh=st[st[rt].l].hsh*pw[r-m]+st[st[rt].r].hsh;
}
void upd (int &rt, int pre, int pos, char v, int l, int r) {
    rt=cnt++;
    st[rt].l=st[pre].l;
    st[rt].r=st[pre].r;
    if (l==r) {
        st[rt].c=v;
        st[rt].hsh=v;
        return;
    }
    int m=l+r>>1;
    if (pos<=m) upd(st[rt].l, st[pre].l, pos, v, l, m);
    else upd(st[rt].r, st[pre].r, pos, v, m+1, r);
    st[rt].hsh=st[st[rt].l].hsh*pw[r-m]+st[st[rt].r].hsh;
}
bool cmptree(int rt1, int rt2, int l, int r) {
    if (l==r) return st[rt1].c<st[rt2].c;
    int m=l+r>>1;
    if (st[st[rt1].l].hsh==st[st[rt2].l].hsh)
        return cmptree(st[rt1].r, st[rt2].r, m+1, r);
    return cmptree(st[rt1].l, st[rt2].l, l, m);
}
bool cmp(int x, int y) {return cmptree(x, y, 0, L-1);}
char qry(int rt, int pos, int l, int r) {
    if (l==r&&l==pos) return st[rt].c;
    int m=l+r>>1;
    if (pos<=m) return qry(st[rt].l, pos, l, m);
    else return qry(st[rt].r, pos, m+1, r);
}
int main() {
    scanf(" %s", S);
    scanf("%d", &N);
    pw[0]=1;
    L=strlen(S);
    for (int i=1; i<=L; i++)
        pw[i]=1LL*pw[i-1]*seed;
    build(root[0], 0, L-1);
    for (int n=1, pos; n<N; n++) {
        scanf("%d %c", &pos, &ch);
        pos--;
        upd(root[n], root[n-1], pos, ch, 0, L-1);
    }
    sort(root, root+N, cmp);
    scanf("%d", &Q);
    for (int q=1, i, j; q<=Q; q++) {
        scanf("%d%d", &i, &j);
        i--;
        j--;
        printf("%c\n", qry(root[i], j, 0, L-1));
    }
}
