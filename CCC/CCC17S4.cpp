#include <bits/stdc++.h>
using namespace std;
const int MAXN=100004;
int N, M, D, nodes[MAXN], max_edge, Time, total_edge, cnt;
typedef tuple<int, int, int, int> carrot;
vector<carrot> paths;
bool compare(carrot a, carrot b) {
    if (get<2>(a)==get<2>(b)) return get<3>(a)<get<3>(b);
    return get<2>(a)<get<2>(b);
}
inline int findRoot(int i) {
    if (nodes[i]!=i) nodes[i]=findRoot(nodes[i]);
    return nodes[i];
}
inline void Merge(int i, int j) {
    nodes[findRoot(i)]=findRoot(j);
}
int main() {
    scanf("%d%d%d", &N, &M, &D);
    for (int m=1, a, b, p; m<=M; m++) {
        scanf("%d%d%d", &a, &b, &p);
        paths.emplace_back(a, b, p, m);
    }
    sort(paths.begin(), paths.end(), compare);
    for (int n=1; n<=N; n++) nodes[n]=n;
    for (auto m: paths) {
        if (total_edge==N-1) break;
        cnt++;
        int a=get<0>(m);
        int b=get<1>(m);
        int c=get<2>(m);
        int d=get<3>(m);
        if (findRoot(a)!=findRoot(b)) {
            total_edge++;
			Merge(a,b);
			max_edge=c;
			if (d>=N) Time++;
        }
    }
    if (get<3>(paths[cnt-1])<N) {printf("%d", Time); return 0;}
    for (int n=1; n<=N; n++) nodes[n]=n;
    for (auto m: paths) {
        int a=get<0>(m);
        int b=get<1>(m);
        int c=get<2>(m);
        int d=get<3>(m);
        if (findRoot(a)!=findRoot(b)) {
            if (c<max_edge||(c==max_edge&&d<N)) Merge(a, b);
            else if (d<N&&c<=D) {printf("%d", Time-1); return 0;}
        }
    }
    printf("%d", Time);
}
