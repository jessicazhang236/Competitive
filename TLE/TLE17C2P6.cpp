#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mod=1000000007;
int H, L, N, S, DP[104][100004];
long long ans;
bool dis[104][100004];
int main() {
    scanf("%d%d%d%d", &N, &H, &L, &S);
    for (int n=1, l, h; n<=N; n++) {
        scanf("%d%d", &l, &h);
        dis[h][l]=true;
    }
    DP[S][0]=1;
    for (int l=0; l<L; l++) {
        for (int h=0; h<H; h++) {
            //printf("%d", DP[h][l]);
            if (!dis[h][l]) {
                if (!dis[h][l+1]) DP[h][l+1]=(DP[h][l+1]+DP[h][l])%mod;
                if (h+1<=H-1&&!dis[h+1][l+1]) DP[h+1][l+1]=(DP[h+1][l+1]+DP[h][l])%mod;
                if (h-1>=0&&!dis[h-1][l+1]) DP[h-1][l+1]=(DP[h-1][l+1]+DP[h][l])%mod;
            }
        }
    }
    ans=0LL;
    for (int h=0; h<H; h++) {if (!dis[h][L]) ans+=DP[h][L];}
    printf("%lld", ans%mod);
}
