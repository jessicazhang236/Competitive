#include <bits/stdc++.h>
using namespace std;
const int MAX=150004;
int N, val[5][MAX], DP[5][MAX], ans=0x3f3f3f3f;
int main() {
    scanf("%d", &N);
    for (int i=1; i<=3; i++) {
        for (int n=1; n<=N; n++) scanf("%d", &val[i][n]);
    }
    int arr[3] = {1, 2, 3};
    for (int i=0; i<6; ++i) {
        memset(DP, 0x3f, sizeof DP);
        DP[3][N]=val[arr[2]][N];
        for (int i=3; i>0; i--) {
            for (int n=N-1; n>0; n--) {
                int m=val[arr[i-1]][n];
                if (i==3) DP[i][n]=DP[i][n+1]+m;
                else DP[i][n]=min(DP[i+1][n+1], DP[i][n+1])+m;
            }
            ans=min(ans, DP[1][1]);
        }
        next_permutation(arr, arr+3);
    }
    printf("%d", ans);
}
