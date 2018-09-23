#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e4+4;
int P, Q, N, X, pw[24], in[24], psa[4*MAXN];
int fun() {
    int ans=0;
    for (int p=1; p<=P; p++) {
        ans=ans*Q+Q-in[p]-1;
    }
    return ans;
}
void sum() {
    for (int p=1; p<=P; p++) {
        for (int i=pw[p]; i<=4*MAXN; i++) {
            if ((i-pw[p])/pw[p+1]==i/pw[p+1]) psa[i]+=psa[i-pw[p]];
        }
    }
}
int main() {
    scanf("%d%d%d", &P, &Q, &N);
    pw[1]=1;
    for (int p=2; p<=P+1; p++) pw[p]=pw[p-1]*Q;
    for (int n=1; n<=N; n++) {
        for (int p=1; p<=P; p++)
            scanf("%d", &in[p]);
        psa[fun()]++;
    }
    sum();
    scanf("%d", &X);
    for (int x=1; x<=X; x++) {
        for (int p=1; p<=P; p++)
            scanf("%d", &in[p]);
        printf("%d\n", psa[fun()]);
    }
}
