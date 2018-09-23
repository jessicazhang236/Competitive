#include <bits/stdc++.h>
using namespace std;
int N, p, q, vis[10004], friends[10004];
int main() {
    scanf("%d", &N);
    for (int n=0, a, b; n<N; n++) {
        scanf("%d %d", &a, &b);
        friends[a]=b;
    }
    scanf("%d %d", &p, &q);
    while (p&&q) {
        int dis=-1;
        memset(vis, 0, sizeof(vis));
        while (p!=q&&!vis[p]) {
            vis[p]=1;
            p=friends[p];
            dis++;
        }
        if (p==q)
            printf("Yes %d\n", dis);
        else
            printf("No\n");
        scanf("%d %d", &p, &q);
    }
}
