#include <bits/stdc++.h>
using namespace std;
double rt, eps=1e-6;
int N;
int main() {
    scanf("%d", &N);
    for (int n=1, a, b; n<=N; n++) {
        scanf("%d%d", &a, &b);
        if (a==0) {
            if (b!=0) {
                printf("no");
                return 0;
            }
        }
        else {
            double k=1.0*b/a;
            if (rt==0.0) rt=k;
            else {
                if (fabs(rt-k)>eps) {
                    printf("no");
                    return 0;
                }
            }
        }
    }
    printf("yes");
}
