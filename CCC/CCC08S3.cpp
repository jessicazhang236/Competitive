#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, R, C, dis[24][24], movement[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
queue<pii> path;
bool vis[24][24];
bool check(int i, int j) {
    if (i>0&&j>0&&i<=R&&j<=C&&!vis[i][j])
        return true;
    return false;
}
int main() {
    scanf("%d", &N);
    for (int n=0; n<N; n++) {
        memset(dis, 0, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        char grid[24][24];
        scanf("%d%d", &R, &C);
        for (int r=1; r<=R; r++)
            scanf("%s", grid[r]+1);
        path.push({1, 1});
        vis[1][1]=true;
        dis[1][1]=1;
        while (!path.empty()) {
            pii a=path.front();
            int m=a.first;
            int n=a.second;
            path.pop();
            if (grid[m][n]=='+') {
                for (int i=0; i<4; i++) {
                    int r=m+movement[i][0];
                    int c=n+movement[i][1];
                    if (check(r, c)&&grid[r][c]!='*') {
                        path.push({r, c});
                        dis[r][c]=dis[m][n]+1;
                        vis[r][c]=true;
                    }
                }
            }
            else if (grid[m][n]=='-') {
                for (int i=2; i<4; i++) {
                    int r=m;
                    int c=n+movement[i][1];
                    if (check(r, c)&&grid[r][c]!='*') {
                        path.push({r, c});
                        dis[r][c]=dis[m][n]+1;
                        vis[r][c]=true;
                    }
                }
            }
            else if (grid[m][n]=='|') {
                for (int i=0; i<2; i++) {
                    int r=m+movement[i][0];
                    int c=n;
                    if (check(r, c)&&grid[r][c]!='*') {
                        path.push({r, c});
                        dis[r][c]=dis[m][n]+1;
                        vis[r][c]=true;
                    }
                }
            }
        }
        if (vis[R][C])
            printf("%d\n", dis[R][C]);
        else
            printf("-1\n");
    }
}
