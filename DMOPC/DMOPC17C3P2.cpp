#include <bits/stdc++.h>
using namespace std;
int N, Q, i, r, v;
map<int, int> ind[3];
int main() {
    scanf("%d%d", &N, &Q);
    for (int q=1, cmd; q<=Q; q++) {
        scanf("%d", &cmd);
        ind[1][2*N+1]=N;
        ind[1][0]=1;
        ind[2][0]=1;
        ind[2][2*N+1]=N;
        if (cmd==1) {
            scanf("%d%d%d", &r, &i, &v);
            ind[r][v]=r;
        }
        else {
            scanf("%d", &v);
            int ans=-prev(ind[1].upper_bound(v))->second+ind[1].upper_bound(v)->second-prev(ind[2].upper_bound(v))->second+ind[2].upper_bound(v)->second+2;
            printf("%d\n", ans);
        }
    }
}
