#include <bits/stdc++.h>
using namespace std;
int N, cost;
int main() {
    scanf("%d", &N);
    while (N>1) {
        for (int n=2; n<=N; n++) {
            if (!(N%n)) {
                int a=N/n;
                N-=a;
                cost+=(n-1);
                break;
            }
        }
    }
    printf("%d", cost);
}
