#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200004, LN=20;
int N, K, Q, a[MAXN], b[54], st[LN][MAXN];
ll psa[MAXN], ans[MAXN];
typedef pair<int, int> pii;
struct trio{
    int id, l, r;
};
vector<trio> queries[54];
void build(int ind) {
    for (int n=1, i=1; n<=N; n++) {
        while (i<=N&&psa[i]-psa[n-1]<=b[ind]) i++;
        st[0][n]=i;
    }
    st[0][N+1]=N+1;
    for (int i=1; i<LN; i++) {
        for (int n=1; n<=N+1; n++) {
            st[i][n]=st[i-1][st[i-1][n]];
        }
    }
}
int query(int l, int r){
    int cnt=1;
    for(int i=19; i>=0; i--){
        if(st[i][l]>r) continue;
        cnt+=(1<<i);
        l=st[i][l];
    }
    return cnt;
}
int main() {
    scanf("%d%d%d", &N, &K, &Q);
    for (int n=1; n<=N; n++) {
        scanf("%d", &a[n]);
        psa[n]=psa[n-1]+a[n];
    }
    for (int k=1; k<=K; k++) scanf("%d", &b[k]);
    for (int q=1, j, l, r; q<=Q; q++) {
        scanf("%d%d%d", &j, &l, &r);
        queries[j].push_back({q, l, r});
    }
    for (int k=1; k<=K; k++) {
        if (!queries[k].size()) continue;
        build(k);
        for (auto p: queries[k]) {
            if (st[19][p.l]<=p.r) ans[p.id]=-1;
            else ans[p.id]=query(p.l, p.r);
        }
    }
    for (int q=1; q<=Q; q++) printf("%lld\n", ans[q]);
}
