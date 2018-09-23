#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+4;
int N, init[MAXN], st[MAXN];
ll T;
char cell[MAXN];
void fun(int i) {
    int pos=(1LL<<i)%N;
    int cng=(N-pos)%N;
    for (int n=0; n<N; n++) st[n]=init[(n+pos)%N]^init[(n+cng)%N];
    memcpy(init, st, sizeof init);
}
int main() {
    scanf("%d%lld", &N, &T);
    scanf("%s", cell);
    for (int n=0; n<N; n++) init[n]=cell[n]-'0';
    for (int n=59; n>=0; n--) {
        if ((T>>n)&1) fun(n);
    }
    for (int n=0; n<N; n++) printf("%d", init[n]);
}
