#include <bits/stdc++.h>
using namespace std;
int N, M, stx, sty, ans[104][104];
bool see[104][104], vis[104][104];
char grid[104][104];
struct cell{
    int x, y, dist;
};
struct comp {
    bool operator()(cell &a, cell &b) {
        return a.dist>b.dist;
    }
};
priority_queue<cell, vector<cell>, comp> Q;
void camera(int x, int y) {
    for (int n=0; n<x; n++) {
        if (grid[x-n][y]=='.') see[x-n][y]=1;
        else if (grid[x-n][y]=='S') see[x-n][y]=1;
        else if (grid[x-n][y]=='W') break;
    }
    for (int n=0; y+n<=M; n++) {
        if (grid[x][y+n]=='.') see[x][y+n]=1;
        else if (grid[x][y+n]=='S') see[x][y+n]=1;
        else if (grid[x][y+n]=='W') break;
    }
    for (int n=0; n<y; n++) {
        if (grid[x][y-n]=='.') see[x][y-n]=1;
        else if (grid[x][y-n]=='S') see[x][y-n]=1;
        else if (grid[x][y-n]=='W') break;
    }
    for (int n=0; x+n<=N; n++) {
        if (grid[x+n][y]=='.') see[x+n][y]=1;
        else if (grid[x+n][y]=='S') see[x+n][y]=1;
        else if (grid[x+n][y]=='W') break;
    }
}
bool check(int x, int y) {
    if (see[x][y]) return false;
    if (grid[x][y]=='W') return false;
    if (grid[x][y]=='C') return false;
    if (vis[x][y]) return false;
    if (x>N||x<=0||y>M||y<=0) return false;
    return true;
}
int main() {
    memset(ans, 0x3f, sizeof ans);
    scanf("%d%d", &N, &M);
    for (int n=1; n<=N; n++)
        scanf("%s", grid[n]+1);
    for (int n=1; n<=N; n++) {
        for (int i=1; i<=M; i++) {
            if (grid[n][i]=='C') {
                camera(n, i);
                see[n][i]=1;
            }
            else if (grid[n][i]=='S') {
                stx=n, sty=i;
            }
        }
    }
    if (see[stx][sty]) {
        for (int n=1; n<=N; n++) {
            for (int m=1; m<=M; m++) {
                if (grid[n][m]=='.') printf("-1\n");
            }
        }
        return 0;
    }
    Q.push({stx, sty, 0});
    //vis[stx][sty]=1;
    while (!Q.empty()) {
        auto c=Q.top();
        //printf("%d %d %d\n", c.x, c.y, c.dist);
        Q.pop();
        int x=c.x;
        int y=c.y;
        if (vis[x][y]) continue;
        else vis[x][y]=1;
        ans[x][y]=min(ans[x][y], c.dist);
        if (grid[x][y]=='L'&&check(x, y-1)) {Q.push({x, y-1, c.dist});} //vis[x][y-1]=1;}
        else if (grid[x][y]=='R'&&check(x, y+1)) {Q.push({x, y+1, c.dist});}// vis[x][y+1]=1;}
        else if (grid[x][y]=='U'&&check(x-1, y)) {Q.push({x-1, y, c.dist});} // vis[x-1][y]=1;}
        else if (grid[x][y]=='D'&&check(x+1, y)) {Q.push({x+1, y, c.dist});} // vis[x+1][y]=1;}
        else if (grid[x][y]=='.') {
            if (check(x, y+1)) {Q.push({x, y+1, c.dist+1});} // vis[x][y+1]=1;}
            if (check(x, y-1)) {Q.push({x, y-1, c.dist+1});} // vis[x][y-1]=1;}
            if (check(x-1, y)) {Q.push({x-1, y, c.dist+1});} // vis[x-1][y]=1;}
            if (check(x+1, y)) {Q.push({x+1, y, c.dist+1});} // vis[x+1][y]=1;}
        }
        else if (grid[x][y]=='S') {
            if (check(x, y+1)) {Q.push({x, y+1, c.dist+1});} // vis[x][y+1]=1;}
            if (check(x, y-1)) {Q.push({x, y-1, c.dist+1});} // vis[x][y-1]=1;}
            if (check(x-1, y)) {Q.push({x-1, y, c.dist+1});} // vis[x-1][y]=1;}
            if (check(x+1, y)) {Q.push({x+1, y, c.dist+1});} // vis[x+1][y]=1;}
        }
    }
    for (int n=1; n<=N; n++) {
        for (int i=1; i<=M; i++) {
            if (grid[n][i]=='.'&&ans[n][i]==0x3f3f3f3f) printf("-1\n");
            else if (grid[n][i]=='.'&&!see[n][i]) printf("%d\n", ans[n][i]);
        }
    }
}
