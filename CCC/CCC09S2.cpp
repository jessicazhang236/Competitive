#include <bits/stdc++.h>
using namespace std;
int R, L, row[34], Pow[10], ans, newA[34];
bool vis[258];
int main() {
    scanf("%d%d", &R, &L);
    Pow[0]=1;
    for (int l=1; l<=L; l++) Pow[l]=Pow[l-1]*2;
    for (int r=R; r>0; r--) {
        for (int l=1, n; l<=L; l++) {
            scanf("%d", &n);
            row[r]+=n*Pow[L-l];
        }
    }
    for (int r=1; r<=R; r++) {
        memcpy(newA, row, (R+1)*sizeof(int));
        for (int i=r-1; i>0; i--) newA[i]^=newA[i+1];
        if (!vis[newA[1]]) {ans++; vis[newA[1]]=1;}
    }
    printf("%d", ans);
}
