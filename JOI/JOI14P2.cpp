#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN=2e5+4;
ll ans;
int N, K, l, r, ind[3*MAXN], RMQ[20][MAXN*3], BIT[MAXN*3];
inline void build() {
    for (int i=1; i<=19; i++) {
        for (int j=0; j+(1<<i-1)<MAXN*3; j++)
            RMQ[i][j]=max(RMQ[i-1][j], RMQ[i-1][j+(1<<i-1)]);
    }
}
int query(int l, int r) {
    if (l==r) return RMQ[0][l];
    r--;
    int len=r-l+1;
    int k=(int)floor(log2(len));
    return max(RMQ[k][l], RMQ[k][r-(1<<k)+1]);
}
inline void update(int m, int val) {
    while (m<3*MAXN) {
        BIT[m]+=val;
        m+=m&(-m);
    }
}
inline int Query(int m) {
    ll ans=0LL;
    while (m>0) {
        ans+=BIT[m];
        m-=m&(-m);
    }
    return ans;
}
vector<int> T, V;
vector<pii> num, upd;
bool cmp(pii a, pii b) {
    return a.first>b.first;
}
int main() {
    //freopen("C:\\Users\\zhanghao\\Downloads\\fortune_telling2-data (1)\\fortune_telling2-data\\in\\01-01.txt", "r", stdin);
    scanf("%d%d", &N, &K);
    r=K-1;
    for (int n=1, a, b; n<=N; n++) {
        scanf("%d%d", &a, &b);
        num.emplace_back(a, b);
        V.push_back(a);
        V.push_back(b);
    }
    for (int k=1, t; k<=K; k++) {
        scanf("%d", &t);
        T.push_back(t);
        V.push_back(t);
    }
    memset(ind, -1, sizeof ind);
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    for (int k=0; k<K; k++) ind[lower_bound(V.begin(), V.end(), T[k])-V.begin()]=k;
    for (int i=0; i<V.size(); i++) RMQ[0][i]=ind[i];
    build();
    for (int n=0, p, q, m, b; n<N; n++) {
        p=max(num[n].first, num[n].second);
        q=min(num[n].first, num[n].second);
        m=lower_bound(V.begin(), V.end(), q)-V.begin();
        b=lower_bound(V.begin(), V.end(), p)-V.begin();
        upd.emplace_back(query(m, b), n);
    }
    sort(upd.begin(), upd.end(), cmp);
    for (int t=0, c; t<N; t++) {
        l=upd[t].first;
        int n=upd[t].second;
        int p=max(num[n].first, num[n].second);
        int q=min(num[n].first, num[n].second);
        int b=lower_bound(V.begin(), V.end(), p)-V.begin();
        for (; r>=max(l, 0); r--) {
            int m=lower_bound(V.begin(), V.end(), T[r])-V.begin();
            update(m+1, 1);
        }
        c=Query(V.size())-Query(b);
        if (l!=-1) {
            if (c%2) ans+=q;
            else ans+=p;
            printf("%lld %d %d\n", ans, p, q);
        }
        else {
            if (c%2) ans+=num[n].second;
            else ans+=num[n].first;
            printf("%lld %d %d\n", ans, p, q);
        }
    }
    printf("%lld", ans);
}
