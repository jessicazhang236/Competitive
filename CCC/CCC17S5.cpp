#include <bits/stdc++.h>
using namespace std;
int N, b=390, M, Q, L, R, x, lines[150004], people[150004], sum[400], shifts[150004], ind[150004], blocks[150004][400];
vector<int> trains[150004];
inline int val (int i) {
    int a=lines[i];
    return (ind[i]+trains[a].size()-shifts[a])%trains[a].size();
}
int main() {
    memset(blocks, -1, sizeof blocks);
    scanf("%d%d%d", &N, &M, &Q);
    for (int n=1, i; n<=N; n++) {
        scanf("%d", &i);
        lines[n]=i;
        blocks[i][n/b]=n;
        trains[i].push_back(n);
        ind[n]=trains[i].size()-1;
    }
    for (int n=1; n<=N; n++) {
        scanf("%d", &people[n]);
        sum[n/b]+=people[n];
    }
    for (int q=1, c; q<=Q; q++) {
        scanf("%d", &c);
        if (c==1) {
            scanf("%d%d", &L, &R);
            int ans=0;
            if (R-L<b) {
                for (int i=L; i<=R; i++) ans+=people[trains[lines[i]][val(i)]];
            }
            else {
                int l=L/b+1;
                int r=R/b;
                for (int i=l; i<r; i++) {
                    ans+=sum[i];
                }
                for (int i=L; i<l*b; i++) ans+=people[trains[lines[i]][val(i)]];
                for (int i=r*b; i<=R; i++) ans+=people[trains[lines[i]][val(i)]];
            }
            printf("%d\n", ans);
        }
        else {
            scanf("%d", &x);
            int m=-1;
            int n=0;
            for (int i=0; i<=b; i++) {
                int p=blocks[x][i];
                if (p==-1) continue;
                if (m==-1) m=i;
                sum[i]+=n;
                n=people[trains[lines[p]][val(p)]];
                sum[i]-=n;
            }
            sum[m]+=n;
            shifts[x]=(shifts[x]+1)%trains[x].size();
        }
    }
    return 0;
}
