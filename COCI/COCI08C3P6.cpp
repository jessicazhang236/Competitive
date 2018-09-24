#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> trio;
const int MOD=1e9+7, MAXN=1504, MAXM=5004;
int N, M, dist[MAXN];
vector<trio> adj[MAXN];
vector<int> proc;
priority_queue<pii> Q;
ll lst[MAXN], st[MAXN], ans[MAXM];
int main() {
    scanf("%d%d", &N, &M);
    for (int m=0, o, d, l; m<M; m++) {
        scanf("%d%d%d", &o, &d, &l);
        adj[o].emplace_back(d, l, m);
    }
    for (int n=1; n<=N; n++) {
        proc.clear();
        memset(lst, 0, sizeof lst);
        memset(st, 0, sizeof st);
        memset(dist, 0x3f, sizeof dist);
        dist[n]=0;
        lst[n]=1;
        Q.push({0, n});
        while (!Q.empty()) {
            int d=-Q.top().first;
            int cur=Q.top().second;
            Q.pop();
            if (d>dist[cur]) continue;
            proc.push_back(cur);
            for (auto p: adj[cur]) {
                int a=get<0>(p);
                int b=get<1>(p);
                if (d+b<dist[a]) {
                    dist[a]=d+b;
                    Q.push({-dist[a], a});
                    lst[a]=lst[cur];
                }
                else if (d+b==dist[a]) {
                    lst[a]+=lst[cur];
                    lst[a]%=MOD;
                }
            }
        }
        reverse(proc.begin(), proc.end());
        for (int cur: proc) {
            st[cur]=1;
            for (auto p: adj[cur]) {
                int a=get<0>(p);
                int b=get<1>(p);
                int c=get<2>(p);
                if (dist[a]>=dist[cur]+b) {
                    st[cur]+=st[a];
                    st[cur]%=MOD;
                    ans[c]+=(lst[cur]*st[a]);
                    ans[c]%=MOD;
                }
            }
        }
    }
    for (int m=0; m<M; m++) printf("%lld\n", ans[m]);
}
