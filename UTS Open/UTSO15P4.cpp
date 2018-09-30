#include <bits/stdc++.h>
using namespace std;
const int MAXN=2004;
typedef tuple<int, int, int> trio;
int N, M, T;
double state[MAXN][MAXN], num, den;
vector<trio> adj[MAXN];
int main() {
    scanf("%d%d%d", &N, &M, &T);
    for (int m=1, a, b, c, d; m<=M; m++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        adj[a].emplace_back(b, c, d);
    }
    state[0][1]=1.0;
    state[1][1]=-1.0;
    for (int t=0; t<=T; t++) {
        for (int n=1; n<=N; n++) {
            if (t!=0) state[t][n]+=state[t-1][n];
            for (auto p: adj[n]) {
                int u=get<0>(p);
                int l=get<1>(p);
                int h=get<2>(p);
                double tot=h-l+1.0;
                h=min(h+t, T);
                if (n==N||l+t>T) continue;
                state[l+t][u]+=state[t][n]/((double)adj[n].size()*tot);
                state[h+1][u]-=state[t][n]/((double)adj[n].size()*tot);
            }
        }
    }
    /*for (int t=0; t<=T; t++) {
        for (int n=1; n<=N; n++) printf("%.6lf ", state[t][n]);
        printf("\n");
    }*/
    for (int t=0; t<=T; t++) {
        num+=t*state[t][N];
        den+=state[t][N];
    }
    printf("%.6f", num/den);
}
