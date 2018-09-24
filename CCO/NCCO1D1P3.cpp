#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, C;
bool flg;
deque<pii> Min, Max;
int main() {
    scanf("%d%d%d", &N, &M, &C);
    for (int n=1, l; n<=N; n++) {
        scanf("%d", &l);
        while (!Min.empty()&&Min.front().second+M<=n) Min.pop_front();
        while (!Min.empty()&&Min.back().first>=l) Min.pop_back();
        Min.push_back({l, n});
        while (!Max.empty()&&Max.front().second+M<=n) Max.pop_front();
        while (!Max.empty()&&Max.back().first<=l) Max.pop_back();
        Max.push_back({l, n});
        if (n>=M&&Max.front().first-Min.front().first<=C) {
            printf("%d\n", n-M+1);
            flg=1;
        }
    }
    if (!flg) printf("NONE\n");
}
