#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, psa[654][654], a_0[654], b_0[654];
vector<pii> num;
int main() {
    scanf("%d", &N);
    for (int n=1, a, b; n<=N; n++) {
        scanf("%d%d", &a, &b);
        if (!a) a_0[b]++;
        if (!b) b_0[a]++;
        psa[a][b]++;
        num.emplace_back(a, b);
    }
    for (int i=650; i>=0; i--) {
        for (int j=650; j>=0; j--) {
            psa[i][j]+=(psa[i+1][j]+psa[i][j+1]-psa[i+1][j+1]);
        }
    }
    for (int n=0; n<N; n++) {
        int x=0, y=0;
        int a=num[n].first;
        int b=num[n].second;
        if (a==650) x=a_0[b];
        if (b==650) y=b_0[a];
        printf("%d %d\n", psa[a+1][b+1]+1, psa[a][0]+psa[0][b]-psa[a][b]-x-y);
    }
}
