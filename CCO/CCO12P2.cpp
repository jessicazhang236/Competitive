/*#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int MAXN=2e4+4;
int N, M;
ll sd[MAXN], ssd[MAXN];
bool vis[MAXN];
vector<pii> adj[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> Queue;
inline void update() {
    memset(sd, 0x3f, sizeof sd);
    memset(ssd, 0x3f, sizeof ssd);
    Queue.push({0, 1});
    sd[1]=0;
    ssd[1]=0;
    vis[1]=true;
	while (!Queue.empty()) {
		pii a=Queue.top();
        int m=a.second;
		Queue.pop();
		for (int i=0; i<adj[m].size(); i++) {
            pii p=adj[m][i];
            if (ssd[m]+p.second<sd[p.first]) {
                ssd[p.first]=ssd[m]+p.second;
                sd[p.first]=sd[m]+p.second;
            }
            else if (sd[m]+p.second<=sd[p.first]) {
                ssd[p.first]=min(ssd[m]+p.second, sd[p.first]);
                sd[p.first]=sd[m]+p.second;
            }
            else if (sd[m]+p.second<ssd[p.first]) ssd[p.first]=sd[m]+p.second;
            if (!vis[p.second]) {
                vis[p.second]=true;
                Queue.push({sd[p.second], p.second});
            }
		}
		vis[m]=false;
	}
}
int main() {
    scanf("%d%d", &N, &M);
    for (int m=1, a, b, l; m<=M; m++) {
        scanf("%d%d%d", &a, &b, &l);
        adj[a].emplace_back(b, l);
    }
    update();
    if (ssd[N]==0x3f3f3f3f3f3f3f3f) printf("-1");
    else printf("%lld", ssd[N]);
}*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN=2e4+4;
const int INF=0x3f3f3f3f;
int N, M, d1[MAXN], d2[MAXN], ans=INF;
vector<pii> adj1[MAXN], adj2[MAXN];
int update(vector<pii> *adj, int *sd, int nd) {
    priority_queue<pii, vector<pii>, greater<pii>> Queue;
    Queue.push({0, nd});
    sd[nd]=0;
	while (!Queue.empty()) {
		pii a=Queue.top();
        int m=a.second;
		Queue.pop();
        for (int i=0; i<adj[m].size(); i++) {
            pii p=adj[m][i];
            if (sd[m]+p.second<sd[p.first]) {
                sd[p.first]=sd[m]+p.second;
                Queue.push({sd[p.first], p.first});
            }
		}
	}
}
int main() {
    scanf("%d%d", &N, &M);
    for (int m=1, a, b, l; m<=M; m++) {
        scanf("%d%d%d", &a, &b, &l);
        adj1[a].emplace_back(b, l);
        adj2[b].emplace_back(a, l);
    }
    memset(d1, 0x3f, sizeof d1);
    memset(d2, 0x3f, sizeof d2);
    update(adj1, d1, 1);
    update(adj2, d2, N);
    for (int n=1; n<=N; n++) {
        for (int i=0, a, b; i<adj1[n].size(); i++) {
            a=adj1[n][i].first;
            b=adj1[n][i].second;
            if (d1[n]==INF||d2[a]==INF) continue;
            if (d1[n]+b+d2[a]==d1[N]) continue;
            ans=min(ans, d1[n]+b+d2[a]);
        }
    }
    if (ans==INF) printf("-1");
    else printf("%d", ans);
}
