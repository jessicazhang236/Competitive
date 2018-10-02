#include <bits/stdc++.h>
using namespace std;
int H, D, E, S[10], A[10], T[1004], L[1004], X[1004], MaxT;
double sum;
int main() {
    scanf("%d%d%d", &H, &D, &E);
    for (int d=1; d<=D; d++) scanf("%d%d", &A[d], &S[d]);
    for (int e=1; e<=E; e++) {
        scanf("%d%d%d", &T[e], &L[e], &X[e]);
        MaxT=max(MaxT, T[e]+L[e]);
    }
    for (int t=0; t<=MaxT; t++) {
        int tot=0;
        for (int e=1; e<=E; e++) {
            if (t>=T[e]&&t<T[e]+L[e]) tot+=X[e];
        }
        double Min=tot*1.0;
        for (int d=1; d<=D; d++) {
            Min=min(Min, (max(tot-S[d], 0))*(1.0-A[d]/100.0));
        }
        sum+=Min;
    }
    if (sum>=H) printf("DO A BARREL ROLL!");
    else printf("%.2f", H-sum);
}
