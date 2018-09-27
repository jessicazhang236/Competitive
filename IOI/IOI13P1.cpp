#include <bits/stdc++.h>
using namespace std;
const int MAX=100004;
typedef pair<int, int> pii;
int /*path,*/ max_d, end1, max_len, end2, Time[MAX], par[MAX], /*len, dif, r,*/ dist[MAX]/*lp[MAX], slp[MAX],*/;
vector<pii> adj[MAX];
priority_queue<int> d;
bool vis[MAX];
void dfs1 (int cur, int src, int dis) {
    vis[cur]=true;
    if (dis>max_d) {max_d=dis; end1=cur;}
    for (auto p: adj[cur]) {
        int i=p.first;
        if (i!=src&&!vis[i]) dfs1(i, cur, dis+p.second);
    }
}
void dfs2 (int cur, int src, int dis) {
    if (dis>max_d) {max_d=dis; end2=cur;}
    for (auto p: adj[cur]) {
        int i=p.first;
        if (i!=src) {
            par[i]=cur;
            Time[i]=p.second;
            dfs2(i, cur, dis+p.second);
        }
    }
}
int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
    for (int m=0; m<M; m++) {
        adj[A[m]+1].emplace_back(B[m]+1, T[m]);
        adj[B[m]+1].emplace_back(A[m]+1, T[m]);
    }
    for (int n=1; n<=N; n++) {
        if (!vis[n]) {
        max_d=-1;
        dfs1(n, -1, 0);
        max_d=-1;
        par[end1]=-1;
        dfs2(end1, -1, 0);
        int R=0x3f3f3f3f, r=0;
        max_len=max(max_len, max_d);
        for (int i=end2; i>0; i=par[i]) {
            r+=Time[i];
            R=min(R, max(r, max_d-r));
        }
        d.push(R);
        }
    }
    int a=d.top();
    d.pop();
    if (!d.size()) return max_len;
    int b=d.top();
    d.pop();
    if (!d.size()) return max(a+b+L, max_len);
    int c=d.top();
    return max(max_len, max(a+b+L, b+c+2*L));
}
#ifndef SIGNATURE_GRADER
int main() {
    scanf("%d%d%d", &N, &M, &L);
    for (int m=0; m<M; m++) scanf("%d", &A[m]);
    for (int m=0; m<M; m++) scanf("%d", &B[m]);
    for (int m=0; m<M; m++) scanf("%d", &T[m]);
    printf("%d", travelTime(N, M, L, A, B, T));
}
#endif // SIGNATURE_GRADER
/*void DFS(int cur, int src) {
    vis[cur]=true;
    for (auto p: adj[cur]) {
        int i=p.first;
        if (i!=src) {
            DFS(i, cur);
            if (lp[i]+p.second>lp[cur]) {slp[cur]=lp[cur]; lp[cur]=lp[i]+p.second;}
            else if (lp[i]+p.second>slp[cur]) slp[cur]=lp[i]+p.second;
        }
    }
    if (lp[cur]+slp[cur]>=len&&lp[cur]-slp[cur]<dif) {
        len=lp[cur]+slp[cur];
        dif=lp[cur]-slp[cur];
        r=lp[cur];
    }
}*/
