#include <bits/stdc++.h>
using namespace std;
int N, R, cnt[1004], Max, s_Max, Mi, mi, sMi, smi;
int main() {
    scanf("%d", &N);
    for (int n=1; n<=N; n++) {
        scanf("%d", &R);
        cnt[R]++;
    }
    for (int r=1; r<=1000; r++) {
        if (cnt[r]>Max) {
            s_Max=Max;
            sMi=Mi;
            smi=mi;
            Max=cnt[r];
            Mi=mi=r;
        }
        else if (cnt[r]==Max) Mi=r;
        else if (cnt[r]>s_Max) {
            s_Max=cnt[r];
            sMi=smi=r;
        }
        else if (cnt[r]==s_Max&&r>sMi) sMi=r;
    }
    if (Mi!=mi) {printf("%d", abs(Mi-mi)); return 0;}
    printf("%d", max(abs(Mi-smi), abs(Mi-sMi)));
}
