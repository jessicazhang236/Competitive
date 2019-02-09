#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=15, MAXM=1e7+4;
int N, Q, L[MAXN], sz[MAXN], A[MAXN], B[MAXN], cmd, b[MAXM];
ll bit[MAXM];
void upd(int id, int d, int val) {
    if (d==N) {
        bit[id]+=val;
        return;
    }
    for (int i=A[d]; i<=L[d]; i+=i&-i) upd(id+(i-1)*sz[d], d+1, val);
}
ll qry(int id, int d) {
    if (d==N) return bit[id];
    ll ans=0LL;
    for (int i=A[d]; i; i-=i&-i) ans-=qry(id+(i-1)*sz[d], d+1);
    for (int i=B[d]; i; i-=i&-i) ans+=qry(id+(i-1)*sz[d], d+1);
    return ans;
}
int main() {
    scanf("%d%d", &N, &Q);
    for (int n=0; n<N; n++) scanf("%d", &L[n]);
    sz[N-1]=1;
    for (int n=N-2; n>=0; n--) sz[n]=sz[n+1]*L[n+1];
    for (int q=1; q<=Q; q++) {
        scanf("%d", &cmd);
        if (cmd==1) {
            int id=0;
            for (int n=0; n<N; n++) {
                scanf("%d", &A[n]);
                id+=(A[n]-1)*sz[n];
            }
            int x;
            scanf("%d", &x);
            upd(0, 0, x-b[id]);
            b[id]=x;
        }
        else {
            for (int n=0; n<N; n++) {
                scanf("%d", &A[n]);
                A[n]--;
            }
            for (int n=0; n<N; n++) scanf("%d", &B[n]);
            printf("%lld\n", qry(0, 0));
        }
    }
}
