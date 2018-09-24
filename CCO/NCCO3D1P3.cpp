#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int R, C, grid[34][34], ind;
bool vis[34][34];
ll ans[34][34][904];
pii st, dest, cng[8]={{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
vector<pii> path[34][34];
queue<pii> Q;
bool check(int a, int b) {
    if (a<=0||a>b) return 1;
    else return 0;
}
int main() {
    scanf("%d%d", &R, &C);
    for (int r=1; r<=R; r++) {
        for (int c=1; c<=C; c++) {
            scanf("%d", &grid[r][c]);
            if (grid[r][c]==3)
                st={r, c};
            else if (grid[r][c]==4)
                dest={r, c};
        }
    }
    for (int r=1; r<=R; r++) {
        for (int c=1; c<=C; c++) {
            if (grid[r][c]!=(2||4)) {
                Q.push({r, c});
                memset(vis, 0, sizeof vis);
                vis[r][c]=1;
                while (!Q.empty()) {
                    int i=Q.front().first;
                    int j=Q.front().second;
                    Q.pop();
                    for (auto p: cng) {
                        int x=i+p.first;
                        int y=j+p.second;
                        if (check(x, R)||check(y, C)||vis[x][y]) continue;
                        vis[x][y]=1;
                        if (!grid[x][y]||grid[x][y]==4) path[r][c].emplace_back(x, y);
                        else if (grid[x][y]==1) Q.push({x, y});
                    }
                }
            }
        }
    }
    Q.push(st);
    memset(vis, 0, sizeof vis);
    ans[st.first][st.second][0]=1;
    vis[st.first][st.second]=1;
    while (!Q.empty()) {
        int cur=Q.size();
        for (int a=1; a<=cur; a++) {
            int x=Q.front().first;
            int y=Q.front().second;
            Q.pop();
            for (auto p: path[x][y]) {
                int i=p.first;
                int j=p.second;
                ans[i][j][ind+1]+=ans[x][y][ind];
                if (!vis[i][j]) {
                    vis[i][j]=1;
                    Q.push(p);
                }
            }
        }
        if (vis[dest.first][dest.second]) {
            printf("%d\n", ind);
            printf("%lld\n", ans[dest.first][dest.second][ind+1]);
            return 0;
        }
        ind++;
    }
    printf("-1\n");
}
