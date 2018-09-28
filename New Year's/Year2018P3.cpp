#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+4;
int N, M, K, h[MAXN];
ll dif[MAXN], l=1LL, r, m, cnt;
int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int n=1; n<=N; n++) {scanf("%d", &h[n]); r=max(r, 0LL+h[n]+K);}
    while (l<r) {
        m=l+r+1>>1;
        memset (dif, 0, sizeof dif);
        cnt=0LL;
        for (int n=1; n<=N; n++) {
            dif[n]+=dif[n-1];
            ll c=dif[n]+h[n];
            if (c<m) {
                ll a=m-c;
                cnt+=a;
                dif[n]+=a;
                dif[min(n+M, N+1)]-=a;
            }
        }
        if (cnt<=K) l=m;
        else r=m-1;
    }
    printf("%lld\n", l);
}
