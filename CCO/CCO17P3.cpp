#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+4;
typedef long long ll;
int N, Q, cnt;
ll bit[MAXN], ans[MAXN];
map<ll, int> mp;
struct drop{
    ll x, y, yy, c;
};
struct q{
    ll x, y;
    int i;
};
vector<drop> paint;
vector<q> query;
bool cmp1(drop a, drop b) {return a.x<b.x;}
bool cmp2(q a, q b) {return a.x<b.x;}
set<ll> val_y;
inline void upd(int i, ll val) {
    for (; i<=1e6; i+=i&-i) bit[i]+=val;
}
inline ll qry (int i) {
    ll out=0LL;
    for (; i; i-=i&-i) out+=bit[i];
    return out;
}
inline ll flip(ll x) {
    ll out=0LL;
    for (int i=0; i<60; i++) {
        out=(out)<<1|(x&1);
        x>>=1;
    }
    return out;
}
int main() {
    scanf("%d%d", &N, &Q);
    ll a, b, c;
    for (int n=0; n<N; n++) {
        //Too many x's and y's... change all to a and b
        scanf("%lld %lld %lld", &a, &b, &c);
        a=flip(a);
        b=flip(b);
        ll aa=a&-a;
        ll bb=b&-b;
        paint.push_back({a-aa, b-bb, b+bb-1, c});
        paint.push_back({a+aa-1, b-bb, b+bb-1, -c});
        val_y.insert(b-bb);
        val_y.insert(b+bb-1);
    }
    for (int q=0; q<Q; q++) {
        scanf("%lld%lld", &a, &b);
        a=flip(a);
        b=flip(b);
        query.push_back({a, b, q});
        val_y.insert(b);
    }
    sort(paint.begin(), paint.end(), cmp1);
    sort(query.begin(), query.end(), cmp2);
    for (ll a: val_y) mp[a]=++cnt;
    for (int i=0, j=0; j<Q&&i<paint.size(); i++) {
        for (; j<Q&&paint[i].x>=query[j].x; j++)
            ans[query[j].i]=qry(mp[query[j].y]-1);
        upd(mp[paint[i].y], paint[i].c);
        upd(mp[paint[i].yy], -paint[i].c);
    }
    for (int q=0; q<Q; q++) printf("%lld\n", ans[q]);
}
