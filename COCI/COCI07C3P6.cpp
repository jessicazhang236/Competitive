#include <bits/stdc++.h>
using namespace std;
const int MAXN=250004, RN=500;
int N, M, A, B, num[MAXN], sum[RN+4], add[RN+4], cnt[RN+4][12];
char d;
int main() {
    scanf("%d%d\n", &N, &M);
    for (int n=1, a; n<=N; n++) {
        scanf("%c", &d);
        a=d-'0';
        num[n]=a;
        sum[n/RN]+=a;
        cnt[n/RN][a]++;
    }
    for (int m=1, a, b, t, ra, rb, ans; m<=M; m++) {
        ans=0;
        scanf("%d%d", &a, &b);
        ra=a/RN;
        rb=b/RN;
        if (ra==rb) {
            while(a<=b) {
                t=(num[a]+add[ra]%10)%10;
                if (num[a]<9) {
                    cnt[ra][num[a]]--;
                    cnt[ra][num[a]+1]++;
                    num[a]++;
                    sum[ra]++;
                }
                else {
                    cnt[ra][9]--;
                    cnt[ra][0]++;
                    num[a]=0;
                    sum[ra]-=9;
                }
                ans+=t;
                a++;
            }
            printf("%d\n", ans);
            continue;
        }
        if (a%RN) {
            while (a<(ra+1)*RN) {
                t=(num[a]+add[ra])%10;
                if (num[a]<9) {
                    cnt[ra][num[a]]--;
                    cnt[ra][num[a]+1]++;
                    num[a]++;
                    sum[ra]++;
                }
                else {
                    cnt[ra][9]--;
                    cnt[ra][0]++;
                    num[a]=0;
                    sum[ra]-=9;
                }
                ans+=t;
                a++;
            }
            ra++;
        }
        if (b%RN!=RN-1) {
            while (b>=rb*RN) {
                t=(num[b]+add[rb]%10)%10;
                if (num[b]<9) {
                    cnt[rb][num[b]]--;
                    cnt[rb][num[b]+1]++;
                    num[b]++;
                    sum[rb]++;
                }
                else {
                    cnt[rb][9]--;
                    cnt[rb][0]++;
                    num[b]=0;
                    sum[rb]-=9;
                }
                ans+=t;
                b--;
            }
            rb--;
        }
        while (ra<=rb) {
            int carrot=0;
            for (int i=1; i<=(add[ra]%10); i++) carrot+=cnt[ra][10-i];
            ans+=sum[ra]+RN*(add[ra]%10)-10*carrot;
            add[ra]++;
            ra++;
        }
        printf("%d\n", ans);
    }
}
