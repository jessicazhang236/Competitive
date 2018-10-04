#include <bits/stdc++.h>
using namespace std;
int R, C, num[104][104], ans;
bool snake[104][104];
bool corner(int a, int b) {
    if (a==1&&b==1) return 1;
    if (a==R&&b==C) return 1;
    if (a==1&&b==C) return 1;
    if (a==R&&b==1) return 1;
    else return 0;
}
int main() {
    scanf("%d%d", &R, &C);
    for (int r=1; r<=R; r++) {
        for (int c=1; c<=C; c++) {
            char cur;
            scanf(" %c", &cur);
            if (cur=='S') {
                snake[r][c]=1;
                if (r+1<=R) num[r+1][c]++;
                if (r-1>=1) num[r-1][c]++;
                if (c+1<=C) num[r][c+1]++;
                if (c-1>=1) num[r][c-1]++;
                if (r+1<=R&&c+1<=C) num[r+1][c+1]++;
                if (r+1<=R&&c-1>=1) num[r+1][c-1]++;
                if (r-1>=1&&c+1<=C) num[r-1][c+1]++;
                if (r-1>=1&&c-1>=1) num[r-1][c-1]++;
            }
        }
    }
    if (R==1) {
        if (C==1) {
            if (snake[R][C]) printf("0");
            else printf("1");
        }
        else {
            for (int c=1; c<=C; c++) {
                if (!num[R][c]&&!snake[R][c]) ans++;
            }
            printf("%d", ans);
        }
        return 0;
    }
    if (C==1) {
        for (int r=1; r<=R; r++) {
            if (!num[r][C]&&!snake[r][C]) ans++;
        }
        printf("%d", ans);
        return 0;
    }
    for (int r=1; r<=R; r++) {
        for (int c=1; c<=C; c++) {
            if (snake[r][c]) continue;
            if (corner(r, c)) {
                if (num[r][c]<=1) ans++;
            }
            else if (r==1||c==1||r==R||c==C) {
                if (num[r][c]<=2) ans++;
            }
            else {
                if (num[r][c]<4) ans++;
            }
        }
    }
    printf("%d", ans);
}
