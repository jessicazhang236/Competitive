#include <bits/stdc++.h>
//#include "secret.h"
using namespace std;
const int MAXN=1004;
int N, A[MAXN], query[MAXN][MAXN];
int Secret(int x,int y){
    return x|y;
}
void build(int L, int R) {
    if (L>=R) return;
    int m=L+R>>1;
    for (int i=m-1; i>=L; i--) {
        if (query[i][m]==-1) query[i][m]=Secret(query[i][i], query[i+1][m]);
    }
    for (int i=m+1; i<=R; i++) {
        if (query[m][i]==-1) query[m][i]=Secret(query[m][i-1], query[i][i]);
    }
    build(L, m-1);
    build(m+1, R);
}
void Init() {
    memset(query, -1, sizeof query);
    for (int n=0; n<N; n++) query[n][n]=A[n];
    build(0, N-1);
}
int Query(int L, int R) {
    for (int i=L; i<R; i++) {
        if (query[L][i]!=-1&&query[i+1][R]!=-1) return Secret(query[L][i], query[i+1][R]);
    }
    return query[L][R];
}
int check(int L, int R) {
    int ans=query[L][L];
    for (int i=L+1; i<=R; i++) ans=ans|query[i][i];
    return ans;
}
int main() {
    scanf("%d", &N);
    for (int n=0; n<N; n++) scanf("%d", &A[n]);
    Init();
    int Q;
    scanf("%d", &Q);
    for (int q=0, L, R; q<Q; q++) {
        scanf("%d %d", &L, &R);
        printf("%d %d\n", Query(L, R), check(L, R));
    }
}
