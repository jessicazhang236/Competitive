#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, H, height[1504][1504];
queue<pii> Queue;
bool vis[1504][1504];
int main() {
    scanf("%d %d", &N, &H);
    for (int n=1; n<=N; n++)
        for (int m=1; m<=N; m++)
            scanf("%d", &height[n][m]);
    Queue.push({1, 1});
    while (!Queue.empty()) {
        int a,b;
        tie(a,b)=Queue.front();
        Queue.pop();
        if (a==N&&b==N) {
            return printf("yes")&&0;
        }
        if (a-1>0&&abs(height[a][b]-height[a-1][b])<=H&&!vis[a-1][b]) {
            Queue.push({a-1, b});
            vis[a-1][b]=true;
        }
        if (a+1<=N&&abs(height[a][b]-height[a+1][b])<=H&&!vis[a+1][b]) {
            Queue.push({a+1, b});
            vis[a+1][b]=true;
        }
        if (b-1>0&&abs(height[a][b]-height[a][b-1])<=H&&!vis[a][b-1]) {
            Queue.push({a, b-1});
            vis[a][b-1]=true;
        }
        if (b+1<=N&&abs(height[a][b]-height[a][b+1])<=H&&!vis[a][b+1]) {
            Queue.push({a, b+1});
            vis[a][b+1]=true;
        }
    }
    printf("no");
}
