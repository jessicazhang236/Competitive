#include <bits/stdc++.h>
using namespace std;
int T, M, X, Y;
inline int maxy (int m, int x) {
    if (!m) return 0;
    int power=pow(5, m-1);
    int val=x/power;
    if (!val||val==4) return 0;
    if (val==(2||3)) return (power+maxy(m-1, x%power));
    return 2*power+maxy(m-1, x%power);
}
int main() {
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        scanf("%d%d%d", &M, &X, &Y);
        if (Y<maxy(M, X)) printf("crystal\n");
        else printf("empty\n");
    }
}
