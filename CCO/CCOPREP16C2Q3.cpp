#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+4, RN=450;
int N, K[MAXN], Q, x, v, blocks[MAXN], pcs[MAXN];
int main() {
    scanf("%d", &N);
    for (int n=0; n<N; n++) {
        scanf("%d", &K[n]);
        blocks[n]=N;
    }
    for (int n=N; n<=MAXN; n++) blocks[n]=N;
    for (int n=N-1; n>=0; n--) {
        if ((n+K[n])/RN>n/RN) {
            pcs[n]=1;
            blocks[n]=n+K[n];
        }
        else {
            pcs[n]=pcs[n+K[n]]+1;
            blocks[n]=blocks[n+K[n]];
        }
    }
    scanf("%d", &Q);
    for (int q=1, cmd; q<=Q; q++) {
        scanf("%d", &cmd);
        if (cmd==1) {
            scanf("%d", &x);
            int ans=0;
            while (x<N) {
                ans+=pcs[x];
                x=blocks[x];
            }
            printf("%d\n", ans);
        }
        else {
            scanf("%d%d", &x, &v);
            int pt=x/RN;
            K[x]=v;
            while (x/RN==pt&&x>=0) {
                if ((x+K[x])/RN>x/RN) {
                    pcs[x]=1;
                    blocks[x]=x+K[x];
                }
                else {
                    pcs[x]=pcs[x+K[x]]+1;
                    blocks[x]=blocks[x+K[x]];
                }
                x--;
            }
        }
    }
}
