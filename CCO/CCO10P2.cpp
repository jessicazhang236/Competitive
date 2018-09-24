#include <bits/stdc++.h>
using namespace std;
const int MAXN=304;
vector<int> adj[MAXN];
int N, D, colour[MAXN], DP[MAXN][6*MAXN];
void dp(int a) {
    DP[a][3*N+1]=min(1, DP[a][3*N+1]);
    int c=colour[a]*2;
    for (int i: adj[a]) dp(i);
    int m=adj[a].size();
    if (!m) DP[a][c+3*N]=0;
    else if (m==1) {
        for (int n=-N; n<=N; n++) DP[a][n+c+3*N]=min(DP[a][n+c+3*N], DP[adj[a][0]][n+3*N+1]);
    }
    else {
        for (int i=-N; i<=N; i++) {
            for (int j=-N; j<=N; j++) DP[a][i+j+c+3*N]=min(DP[a][i+j+c+3*N], DP[adj[a][0]][i+3*N+1]+DP[adj[a][1]][j+3*N+1]);
        }
    }
}
int main() {
	scanf("%d%d", &N, &D);
	for (int n=0, id, C; n<N; n++) {
        scanf("%d", &id);
        scanf("%d%d", &colour[id], &C);
        for (int c=0, i; c<C; c++) {
            scanf("%d", &i);
            adj[id].push_back(i);
        }
        for (int i=-N; i<=N; i++) DP[n][i+1+3*N]=600;
	}
	dp(0);
	int ans=DP[0][D+3*N+1];
	if (ans>=600)
		printf("-1");
	else
		printf("%d", ans);
}
