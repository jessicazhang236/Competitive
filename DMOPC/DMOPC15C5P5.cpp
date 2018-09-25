#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7, MAXN=2e5+4;
typedef long long ll;
int N, ans[MAXN], order[MAXN];
ll BIT[MAXN];
vector<int> adj[MAXN];
void update(int i, ll val) {
    for (; i<=MAXN-3; i+=i&-i) BIT[i]+=val;
}
ll query(int i) {
    ll sum=0LL;
    for (; i; i-=i&-i) sum+=BIT[i];
    return sum;
}
void dfs(int src) {
    ll prev=query(order[src]);
    for (int i: adj[src]) dfs(i);
    ll cur=query(order[src]);
    ans[src]=(cur-prev+1)%MOD;
    update(order[src], ans[src]);
}
int main() {
    scanf("%d", &N);
    for (int n=1, m; n<=N; n++) {
        scanf("%d", &m);
        adj[m].push_back(n);
    }
    for (int n=1, m; n<=N; n++) {
        scanf("%d", &m);
        order[m]=n;
    }
    dfs(adj[0][0]);
    for (int n=1; n<=N; n++) printf("%d ", ans[n]);
}
