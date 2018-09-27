#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pdd;
int N, X;
ll ans, BIT[200004];
vector<pii> pts;
vector<pdd> angles;
vector<ld> sadness;
unordered_map<ld, int> cmprs;
bool cmp(pdd a, pdd b) {
    if (fabs(a.first-b.first)>1e-9) return a.first>b.first+1e-9;
    else return a.second>b.second+1e-9;
}
inline void update(int i, int val) {
    for (; i<=200000; i+=(i&-i))
        BIT[i]+=val;
}
inline ll sum(int i) {
    ll ans=0LL;
    for (; i>0; i-=(i&-i))
        ans+=BIT[i];
    return ans;
}
inline ll rangeSum(int l, int r) {
    return sum(r)-sum(l-1);
}
int main() {
    //freopen("C:\\Users\\zhanghao\\Downloads\\cannons\\cannons.5.in", "r", stdin);
    scanf("%d%d", &N, &X);
    for (int n=1, x, y; n<=N; n++) {
        scanf("%d%d", &x, &y);
        pts.emplace_back(x, y);
    }
    if (N==1) {printf("0"); return 0;}
    for (int i=0; i<N; i++) {
        pii a=pts[i];
        ld k1=atan2(a.second, a.first);
        ld k2=atan2(a.second, (X-a.first));
        sadness.push_back(k2);
        angles.emplace_back(k1, k2);
    }
    sort(angles.begin(), angles.end(), cmp);
    sort(sadness.begin(), sadness.end());
    sadness.erase(unique(sadness.begin(), sadness.end(), [](double a, double b) {
        return fabs(a-b)<=1e-9;
}), sadness.end());
    for (int i=0; i<sadness.size(); i++) cmprs[sadness[i]]=(i+1);
    for (int i=0; i<angles.size(); i++) {
        //printf("%Lf %Lf\n", sadness[i], angles[i].second);
        pdd a=angles[i];
        //printf("%d %d\n", a.first, a.second);
        int m=cmprs[a.second];
        ll b=rangeSum(m, sadness.size());
        //printf("debug\n");
        //printf("%d\n", m);
        update(m, 1LL);
        //printf("debug\n");
        ans+=1LL*b*b;
        //printf("%d\n", b);
    }
    printf("%lld", ans);
}
