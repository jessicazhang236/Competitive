#include <bits/stdc++.h>
using namespace std;
int R, C, Q;
char grid[1004][1004];
int main() {
    scanf("%d%d", &R, &C);
    for (int r=1; r<=R; r++) {
        scanf("%s", grid[r]+1);
    }
    scanf("%d", &Q);
    for (int q=1, x, y; q<=Q; q++) {
        bool check=false;
        scanf("%d%d", &x, &y);
        for (int a=1; a<=R; a++) {
            if (grid[a][x]=='X') {
                printf("Y\n");
                check=true;
                break;
            }
        }
        if (!check) {
            for (int a=1; a<=C; a++) {
                if (grid[y][a]=='X') {
                    printf("Y\n");
                    check=true;
                    break;
                }
            }
        }
        if (!check) printf("N\n");
    }
}
