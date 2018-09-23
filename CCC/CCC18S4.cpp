#include <bits/stdc++.h>
using namespace std;
int N;
typedef long long ll;
unordered_map<int, ll> DP;
ll f(int n) {
    if (n==1||n==2) return 1;
    if (DP[n]) return DP[n];
    int x=n/2;
    int nxt=n/3;
    ll sum=n-x;
    int w=n/x;
    while (x>1) {
        sum+=1LL*(x-nxt)*f(w);
        x=nxt;
        w=n/x;
        nxt=n/(w+1);
    }
    return DP[n]=sum;
}
int main() {
    scanf("%d", &N);
    printf("%lld\n", f(N));
}
