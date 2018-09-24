#include <bits/stdc++.h>
using namespace std;
const int MAXN=504, MAXH=1e6+4, MOD=1e9+7;
typedef long long ll;
int N, K, h[MAXN];
ll fact[MAXH], inv[MAXH], block[MAXN][MAXN], tmp[MAXN], dp[MAXN][MAXN]={1LL};
ll power(ll b, int p) {
	ll v=1;
	while(p) {
		if(p&1) v=(v*b)%MOD;
		b=(b*b)%MOD;
		p>>=1;
	}
	return v%MOD;
}
ll choose(int w, int i) {
    if (w<i||i<0) return 0;
    return (((fact[w]*inv[i])%MOD)*inv[w-i])%MOD;
}
ll permute(int h, int i) {
    if (h<i||h<0||i<0) return 0;
    return (fact[h]*inv[h-i])%MOD;
}
int build(int l, int r, int lst) {
    if (l>r) return 0;
    int u=r;
    for (int i=l; i<=r; i++) {
        if (h[i]<h[u]) u=i;
    }
    int lf=build(l, u-1, h[u]);
    int rt=build(u+1, r, h[u]);
    int ht=h[u]-lst;
    int w=r-l+1;
    int lmt=min(w, K);
    memset(tmp, 0, sizeof tmp);
    for (int i=0; i<=lmt; i++) {
        for (int j=0; j<=lmt-i; j++) {
            tmp[i+j]=(tmp[i+j]+(dp[lf][i]*dp[rt][j])%MOD)%MOD;
        }
    }
    for (int k=0; k<=lmt; k++) {
        for (int i=0; i<=k; i++) {
            dp[u][k]=(dp[u][k]+((choose(w-k+i, i)*permute(ht, i))%MOD*tmp[k-i])%MOD)%MOD;
        }
    }
    return u;
}
int main() {
    fact[0]=1;
    for (int i=1; i<=MAXH-1; i++) fact[i]=fact[i-1]*i%MOD;
    inv[MAXH-1]=power(fact[MAXH-1], MOD-2);
    for (int i=MAXH-2; i>=0; i--) inv[i]=inv[i+1]*(i+1)%MOD;
    scanf("%d%d", &N, &K);
    for (int n=1; n<=N; n++) scanf("%d", &h[n]);
    if (N<K) {
        printf("0");
        return 0;
    }
    int ans=build(1, N, 0);
    printf("%lld\n", dp[ans][K]);
}
