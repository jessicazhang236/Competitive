#include <bits/stdc++.h>
using namespace std;
int D, F, T, W[1004], cnt[1004], Time[1004];
vector<int> adj[1004];
int main() {
    scanf("%d", &D);
    for (int d=1; d<=D; d++) scanf("%d", &W[d]);
    scanf("%d", &F);
    for (int f=1, i, j; f<=F; f++) {
        scanf("%d%d", &i, &j);
        adj[i].push_back(j);
    }
    scanf("%d", &T);
    memset(Time, -1, sizeof Time);
    Time[1]=0;
    for (int t=0; t<=T; t++) {
        for (int d=1; d<=D; d++) {
            if (Time[d]==t) {
                for (int i: adj[d]) {
                    if (Time[i]<t)
                        Time[i]=Time[d]+W[i];
                }
                cnt[d]++;
            }
        }
    }
    for (int d=1; d<=D; d++) printf("%d\n", cnt[d]);
}
