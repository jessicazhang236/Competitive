#include <bits/stdc++.h>
using namespace std;
const int MAX=500004;
int N, lp[MAX], slp[MAX], DP[MAX];
vector<int> adj[MAX];
void DFS1(int cur, int src) {
    for (int i: adj[cur]) {
        if (i!=src) {
            DFS1(i, cur);
            if (lp[i]+1>lp[cur]) {slp[cur]=lp[cur]; lp[cur]=lp[i]+1;}
            else if (lp[i]+1>slp[cur]) slp[cur]=lp[i]+1;
        }
    }
}
void DFS2(int cur, int src, int edge) {
    DP[cur]=max(lp[cur], edge)+1;
    for (int i: adj[cur]) {
        if (i!=src) {
            if (lp[i]+1==lp[cur]) DFS2(i, cur, max(slp[cur], edge)+1);
            else DFS2(i, cur, max(lp[cur], edge)+1);
        }
    }
}
int main() {
    scanf("%d", &N);
    for (int n=1, x, y; n<N; n++) {scanf("%d%d", &x, &y); adj[x].push_back(y); adj[y].push_back(x);}
    DFS1(1, 0);
    DFS2(1, 0, 0);
    for (int n=1; n<=N; printf("%d\n", DP[n++]));
}
