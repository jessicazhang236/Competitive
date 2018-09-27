#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+4;
typedef long long ll;
int N;
ll A[MAXN], psa[MAXN], ans[MAXN];
int main() {
    scanf("%d", &N);
    for (int n=1; n<=N; n++) {
        scanf("%lld", &A[n]);
        psa[n]=psa[n-1]+A[n];
    }
    for (int n=1; n<=(N+1)/2; n++) {
        ans[n]=ans[n-1]+psa[N+1-n]-psa[n-1];
        printf("%lld\n", ans[n]);
    }
    for (int n=(N+1)/2+1; n<=N; n++) printf("%lld\n", ans[N+1-n]);
}
