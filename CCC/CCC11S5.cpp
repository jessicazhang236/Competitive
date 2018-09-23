#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int K, cnt, ini, temp;
bool vis[1<<25|4];
queue<pii> q;
int main() {
    scanf("%d", &K);
    for (int k=1, a; k<=K; k++) {
        ini<<=1;
        scanf("%d", &a);
        ini|=a;
    }
    q.push({ini, 0});
    vis[ini]=1;
    while (!q.empty()) {
        int cur=q.front().first;
        cnt=q.front().second;
        q.pop();
        if (!cur) break;
        cnt++;
        for (int k=0; k<K; k++) {
            if (!(cur&(1<<k))) {
                cur|=(1<<k);
                int nxt=cur;
                int temp=15;
                for (int i=0; i<=K-4; i++) {
                    if (cur==(temp|cur)) nxt&=(~temp);
                    temp<<=1;
                }
                if (!vis[nxt]) {
                    q.push({nxt, cnt});
                    vis[nxt]=1;
                }
                cur&=~(1<<k);
            }
        }
    }
    printf("%d", cnt);
}
