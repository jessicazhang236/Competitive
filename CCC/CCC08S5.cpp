#include <bits/stdc++.h>
using namespace std;
//1=lose, 2=win
int N, state[34][34][34][34];
int main() {
    scanf("%d", &N);
    for (int a=0; a<=30; a++) {
        for (int b=0; b<=30; b++) {
            for (int c=0; c<=30; c++) {
                for (int d=0; d<=30; d++) {
                    if (a>=2&&b>=1&&d>=2) {
                        if (state[a-2][b-1][c][d-2]==1) {state[a][b][c][d]=2; continue;}
                    }
                    if (a>=1&&b>=1&&c>=1&&d>=1) {
                        if (state[a-1][b-1][c-1][d-1]==1) {state[a][b][c][d]=2; continue;}
                    }
                    if (c>=2&&d>=1) {
                        if (state[a][b][c-2][d-1]==1) {state[a][b][c][d]=2; continue;}
                    }
                    if (b>=3) {
                        if (state[a][b-3][c][d]==1) {state[a][b][c][d]=2; continue;}
                    }
                    if (a>=1&&d>=1) {
                        if (state[a-1][b][c][d-1]==1) {state[a][b][c][d]=2; continue;}
                    }
                    state[a][b][c][d]=1;
                }
            }
        }
    }
    for (int n=1, a, b, c, d; n<=N; n++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (state[a][b][c][d]==2) printf("Patrick\n");
        else printf("Roland\n");
    }
}
