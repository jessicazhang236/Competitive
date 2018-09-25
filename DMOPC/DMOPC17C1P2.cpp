#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, sum[100004];
ll ans;
map<int, int> mod;
inline ll choose (int i) {
    if (i<=1)
        return 0LL;
    else
        return i*(i-1LL)/2LL;
}
int main() {
    scanf("%d%d", &N, &M);
    for (int n=1, x; n<=N; n++) {
        scanf("%d", &x);
        sum[n]=(sum[n-1]+x)%M;
        mod[sum[n]]++;
    }
    ans+=mod[0];
    for (auto v: mod)
        ans+=choose(v.second);
    printf("%lld", ans);
}
