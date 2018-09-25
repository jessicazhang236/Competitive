#include <bits/stdc++.h>
using namespace std;
int W, H, N, L, fld[254][254], ans;
int main() {
    scanf("%d%d%d", &W, &H, &N);
    if (N<=W||N<=H) L=N;
    else L=max(H, W);
    for (int h=1; h<=H; h++) {
        for (int w=1; w<=W; w++) {
            scanf("%d", &fld[h][w]);
            fld[h][w]+=(fld[h-1][w]+fld[h][w-1]-fld[h-1][w-1]);
        }
    }
    for (int h=1; h<=H; h++) {
        for (int w=1; w<=W; w++) {
            for (int l=1, a, b; l<=L; l++) {
                a=min(H, h+N/l-1);
                b=min(W, w+l-1);
                ans=max(ans, fld[a][b]-fld[h-1][b]-fld[a][w-1]+fld[h-1][w-1]);
            }
        }
    }
    printf("%d", ans);
}
