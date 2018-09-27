/*
k-D diference array:
update 2^k times.
signs are determined by (-1)^n, n=number of terms in the higher set.
k-D prefix-sum array:
inclusion-exclusion principle
*/
#include <bits/stdc++.h>
using namespace std;
int N, M, ans;
bool dif[10004][10004];
int main() {
    scanf("%d%d", &N, &M);
    for (int m=0, x, y, w, h; m<M; m++) {
        scanf("%d%d%d%d", &x, &y, &w, &h);
        x++;
        y++;
        dif[x][y]=!dif[x][y];
        dif[x+w][y]=!dif[x+w][y];
        dif[x][y+h]=!dif[x][y+h];
        dif[x+w][y+h]=!dif[x+w][y+h];
    }
    for (int c=1; c<=N; c++) {
        for (int r=1; r<=N; r++) {
            dif[r][c]^=dif[r-1][c]^dif[r][c-1]^dif[r-1][c-1];
            /*if (dif[r][c])
                printf("1 ");
            else
                printf("0 ");
                */
            if (dif[r][c]) ans++;
        }
        //printf("\n");
    }
    printf("%d", ans);
}
