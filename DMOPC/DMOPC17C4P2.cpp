#include <bits/stdc++.h>
using namespace std;
const int MAXN=1004;
int N, Q, v[MAXN], par[MAXN], x, y;
vector<int> adj[MAXN];
void dfs(int cur, int src) {
    if (cur==y) return;
    for (int i: adj[cur]) {
        if (i==src) continue;
        par[i]=cur;
        dfs(i, cur);
    }
}
int main() {
    scanf("%d%d", &N, &Q);
    for (int n=1; n<=N; n++) scanf("%d", &v[n]);
    for (int n=1, a, b; n<N; n++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int q=1, cmd; q<=Q; q++) {
        vector<int> num;
        int sum=0;
        int i=0;
        scanf("%d%d%d", &cmd, &x, &y);
        dfs(x, 0);
        while (y) {
            if (cmd==1) sum+=v[y];
            else num.push_back(v[y]);
            i++;
            y=par[y];
        }
        if (cmd==1) printf("%d\n", (int)(1.0*sum/i+0.5));
        else if (cmd==2) {
            sort(num.begin(), num.end());
            if (i%2) printf("%d\n", num[i/2]);
            else printf("%d\n", (int)((1.0*num[i/2-1]+1.0*num[i/2])/2+0.5));
        }
        else {
            sort(num.begin(), num.end());
            int mode=0;
            int cur=1;
            int Max=0;
            for (int n=1; n<num.size(); n++) {
                if (num[n]==num[n-1]) cur++;
                else {
                    if (cur>Max) {
                        Max=cur;
                        mode=num[n-1];
                    }
                    cur=1;
                }
            }
            if (cur>Max) mode=num[num.size()-1];
            printf("%d\n", mode);
        }
    memset(par, 0, sizeof par);
    }
}
