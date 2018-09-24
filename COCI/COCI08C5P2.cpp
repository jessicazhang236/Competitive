#include <bits/stdc++.h>
using namespace std;
int R, G;
int gcd(int a, int b) {
    return b?gcd(b, a%b): a;
}
int main() {
    scanf("%d%d", &R, &G);
    int a=gcd(R, G);
    int sqrt=(int)(pow(a, 0.5));
    for (int i=1; i<=sqrt; i++) {
        if (a%i!=0) continue;
        int j=a/i;
        printf("%d %d %d\n", i, R/i, G/i);
        if (i!=j) printf("%d %d %d\n", j, R/j, G/j);
    }
}
