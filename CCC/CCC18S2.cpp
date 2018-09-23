#include <bits/stdc++.h>
using namespace std;
const int MAXN=104;
int N, grid[104][104], Min=0x3f3f3f3f, mx, my;
int main() {
    scanf("%d", &N);
    for (int n=1; n<=N; n++) {
        for (int i=1; i<=N; i++) {
            scanf("%d", &grid[n][i]);
            if (grid[n][i]<Min) {
                Min=grid[n][i];
                mx=n;
                my=i;
            }
        }
    }
    if (mx==1&&my==1) {
        for (int n=1; n<=N; n++) {
            for (int i=1; i<=N; i++) printf("%d ", grid[n][i]);
            printf("\n");
        }
    }
    else if (mx==N&&my==1) {
        for (int n=1; n<=N; n++) {
            for (int i=N; i>0; i--) printf("%d ", grid[i][n]);
            printf("\n");
        }
    }
    else if (mx==1&&my==N) {
        for (int n=N; n>0; n--) {
            for (int i=1; i<=N; i++) printf("%d ", grid[i][n]);
            printf("\n");
        }
    }
    else {
        for (int n=N; n>=1; n--) {
            for (int i=N; i>0; i--) printf("%d ", grid[n][i]);
            printf("\n");
        }
    }
}
