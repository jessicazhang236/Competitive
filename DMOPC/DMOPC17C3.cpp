#include <bits/stdc++.h>
using namespace std;
const int MAXN=24;
int N, num[MAXN], psa[MAXN];
vector<int> a, b;
int Min1(int i, int sum, int tot) {
    if (i==1) return abs((tot-sum)-sum);
    if (Min1(i-1, sum+num[i-1], tot)<Min1(i-1, sum, tot)) a.push_back(i-1);
    else b.push_back(i-1);
    return min(Min1(i-1, sum+num[i-1], tot), Min1(i-1, sum, tot));
}
int Min2(int n) {
    int tot=psa[n];
    return Min1(n, 0, tot);
}
int main() {
    scanf("%d", &N);
    for (int n=1; n<=N; n++) {
        scanf("%d", &num[n]);
        psa[n]=psa[n-1]+=num[n];
    }
    int n=N/num[1];
    int dif=Min2(n);
    for (int n: a) printf("%d ", n);
    printf("\n");
    for (int n: b) printf("%d ", n);
}
