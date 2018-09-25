#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, check, dist[100004], cnt[100004];
priority_queue<pii, vector<pii>, greater<pii>> Queue;
vector<pii> roads[100004];
int main() {
    scanf("%d%d", &N, &M);
    memset(cnt, 0x3f, sizeof cnt);
    for (int m=0, x, y, t; m<M; m++) {
        scanf("%d%d%d", &x, &y, &t);
        roads[x].push_back({y, t});
        roads[y].push_back({x, t});
    }
    memset(dist, 0x3f, sizeof dist);
    dist[1]=0;
    cnt[1]=0;
	Queue.push({0, 1});
	while (!Queue.empty()) {
		pii a=Queue.top();
		int n=a.second;
		Queue.pop();
		for (auto i: roads[n]) {
			if (dist[n]+i.second<dist[i.first]||(dist[n]+i.second==dist[i.first]&&cnt[n]+1<cnt[i.first])) {
				dist[i.first]=dist[n]+i.second;
				cnt[i.first]=cnt[n]+1;
				Queue.push({dist[i.first], i.first});
			}
		}
	}
    if (dist[N]==0x3f3f3f3f)
        printf("-1");
    else
        printf("%d %d", dist[N], cnt[N]);
}
