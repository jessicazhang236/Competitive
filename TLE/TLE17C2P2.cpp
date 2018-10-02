#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<int> Num;
int main() {
    scanf("%d", &K);
    for (int k=1, v; k<=K; k++) {
        scanf("%d", &v);
        Num.push_back(v);
    }
    sort(Num.begin(), Num.end());
    scanf("%d", &N);
    for (int n=1, h; n<=N; n++) {
        scanf("%d", &h);
        int i=upper_bound(Num.begin(), Num.end(), h)-Num.begin();
        printf("%d\n", h-i);
    }
}
