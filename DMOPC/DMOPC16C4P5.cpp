#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> trio;
int N, M, nodes[200001], ans[200001];
vector<trio> paths;
vector<pii> adj[200001];
bool compare(trio a, trio b) {
    return get<2>(a)>get<2>(b);
}
int findRoot(int i) {
    if (nodes[i]!=i)
        nodes[i]=findRoot(nodes[i]);
    return nodes[i];
}
void Merge(int i, int j) {
    nodes[findRoot(i)]=findRoot(nodes[j]);
}
void DFS (int current, int source, int i=0x3f3f3f3f) {
    ans[current]=i;
    for (auto p:adj[current]) {
        if (p.first!=source)
            DFS(p.first, current, min(i,p.second));
    }
}
int main() {
    scanf ("%d%d", &N, &M);
    for (int m=0, a, b, p; m<M; m++) {
        scanf("%d%d%d", &a, &b, &p);
        paths.emplace_back(a, b, p);
    }
    sort(paths.begin(), paths.end(), compare);
    for (int n=0; n<=N; n++)
        nodes[n]=n;
    for (int m=0; m<M; m++) {
        int a=get<0>(paths[m]);
        int b=get<1>(paths[m]);
        int c=get<2>(paths[m]);
        if (findRoot(a)!=findRoot(b)) {
            adj[a].emplace_back(b, c);
            adj[b].emplace_back(a, c);
			Merge(a,b);
        }
    }
    DFS(1, 1);
    ans[1]=0;
    for (int i=1; i<=N; i++)
        printf("%d\n", ans[i]);
}
