// O(N^3): (state) DP[current position][last traveled distance/ previous node]=max treats
// fun (int cur, int pre) {
//for (int i=1; i<=N; i++) {
//    if (dis(cur, i)<dis(cur, pre))
//        DP[cur][pre]=max(fun(i, cur)+1);
//    }
//}
// O(N^2 logN): find all distances first and sort them
// 3 arrays: dist, DP, CP
// DP[u]=max(DP[u], CP[v]+1), DP[v]=max(DP[v], DP[u]+1)
// When u=0, do not update for v.
// if (d>dist[u]) {dist[u]=d; CP[u]=DP[u];}
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> trio;
int N, dis[2004], DP[2004], CP[2004];
vector<trio> points, dist;
int main() {
    scanf("%d", &N);
    points.emplace_back(0, 0, 0);
    for (int r=1, x, y; r<=N; r++) {
        scanf("%d%d", &x, &y);
        for (auto t: points) {
            int m=get<0>(t);
            int n=get<1>(t);
            int i=get<2>(t);
            dist.emplace_back(((x-m)*(x-m)+(y-n)*(y-n)), i, r);
        }
        points.emplace_back(x, y, r);
        //printf("%d %d %d\n", x, y, n);
    }
    sort(dist.begin(), dist.end());
    for (auto t: dist) {
        int d=get<0>(t);
        int u=get<1>(t);
        int v=get<2>(t);
        //printf("%d %d %d\n", d, u, v);
        if (d>dis[u]) {
            dis[u]=d;
            CP[u]=DP[u];
        }
        if (d>dis[v]) {
            dis[v]=d;
            CP[v]=DP[v];
        }
        if (v) DP[u]=max(DP[u], CP[v]+1);
        if (u) DP[v]=max(DP[v], CP[u]+1);
    }
    printf("%d", DP[0]);
}
