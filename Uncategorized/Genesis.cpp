#include <bits/stdc++.h>
using namespace std;
const int MAXN=204, MAXM=2204, INF=0x3f3f3f3f;
int N, M, ans, adj[MAXN], cnt, lvl[MAXN], ind[MAXN];
struct edge{
    int des, nxt, f, c;
    edge(): des(0), nxt(-1), f(0), c(0){}
    edge(int a, int b, int d): des(a), nxt(b), f(0), c(d){}
}E[MAXM];
void read(int cur, int src, int amt) {
    E[cnt]=edge(src, adj[cur], amt);
    adj[cur]=cnt++;
    E[cnt]=edge(cur, adj[src], 0);
    adj[src]=cnt++;
}
bool bfs(int src, int sink) {
    memset(lvl, -1, sizeof lvl);
    lvl[src]=0;
    queue<int> Q;
    Q.push(src);
    while (Q.size()) {
        int cur=Q.front();
        Q.pop();
        for (int i=adj[cur]; ~i; i=E[i].nxt) {
            int a=E[i].des;
            if (lvl[a]==-1&&E[i].f<E[i].c) {
                lvl[a]=lvl[cur]+1;
                Q.push(a);
            }
        }
    }
    return ~lvl[sink];
}
int dfs(int src, int sink, int flow) {
    if (src==sink) return flow;
    for(int &i=ind[src]; ~i; i=E[i].nxt){
        if(E[i].f<E[i].c&&lvl[E[i].des]==lvl[src]+1)
            if(int f=dfs(E[i].des,sink,min(flow,E[i].c-E[i].f))){
                E[i].f+=f;
                E[i^1].f-=f;
                return f;
            }
    }
    return 0;
}
int main() {
    memset(adj, -1, sizeof adj);
    scanf("%d", &N);
    for (int n=1,a; n<N; n++){
        scanf("%d",&a);
        read(n,n+N,a);
    }
    scanf("%d",&M);
    for(int i=0,a,b;i<M;++i){
        scanf("%d%d",&a,&b);
        read(a+N,b,INF);
    }
    while(bfs(1,N)){
        memcpy(ind,adj,sizeof adj);
        if(int f=dfs(1,N,INF)){
            ans+=f;
        }
    }
    printf("%d\n",ans);
}
