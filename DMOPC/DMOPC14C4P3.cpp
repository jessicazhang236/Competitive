#include <bits/stdc++.h>
using namespace std;
int L, D, x, y, grid[1004][1004], DP[1004][1004];
int main() {
    scanf("%d%d", &L, &D);
    for (int d=1; d<=D; d++) {
        for (int l=1; l<=L; l++) scanf("%d", &grid[l][d]);
    }
    memset(DP, 0x3f, sizeof DP);
    DP[1][1]=grid[1][1];
    for (int d=1; d<=D; d++) {
        for (int l=1; l<=L; l++) DP[l][d]=min(DP[l][d], min(DP[l-1][d], min(DP[l+1][d], DP[l][d-1]))+grid[l][d]);
        for (int l=L; l>=1; l--) DP[l][d]=min(DP[l][d], min(DP[l-1][d], min(DP[l+1][d], DP[l][d-1]))+grid[l][d]);
    }
    scanf("%d%d", &x, &y);
    printf("%d", DP[x+1][y+1]);
}
