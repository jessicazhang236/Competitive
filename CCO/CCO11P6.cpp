#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e4+4;
typedef pair<int, int> pii;
typedef long long ll;
int N, M, T, h[MAXN], lst;
ll ans;
bool tree[MAXN], trees[MAXN][MAXN];
vector<pii> pts;
bool cmp(pii a, pii b) {
    if (a.first==b.first) return a.second<b.second;
    else return a.first<b.first;
}
int main() {
    scanf("%d%d%d", &N, &M, &T);
    for (int t=1, x, y; t<=T; t++) {
        scanf("%d%d", &x, &y);
        if (x==0||x==N||y==0||y==M) continue;
        pts.emplace_back(x, y);
        trees[x][y]=1;
    }
    sort(pts.begin(), pts.end(), cmp);
    for (int n=1; n<=N; n++) {
        stack<pii> s;
        memset(tree, 0, sizeof tree);
        for (int i=lst; i<pts.size(); i++) {
            if (pts[i].first!=n) {lst=i; break;}
            else {tree[i]=1;}
        }
        s.push({0, 0});
        for (int m=0; m<M; m++) {
            h[m]++;
            while (s.top().second&&s.top().second>=h[m]) {
                ll l=s.top().second;
                s.pop();
                ll w=m-s.top().first;
                ans=max(ans, l*w);
            }
            s.push({m, h[m]});
            if (trees[n][m]) h[m]=0;
        }
        while (s.top().second) {
            ll l=s.top().second;
            s.pop();
            ll w=M-s.top().first;
            ans=max(ans, l*w);
        }
    }
    printf("%d", ans);
}
