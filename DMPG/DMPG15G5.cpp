#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, R;
priority_queue<int, vector<int>, greater<int> > pqs[2001];
ll free_food, dp[2001];
template<typename T>
T operator --(priority_queue<T, vector<T>, greater<T>>&pq, int dummy) {
    T ret = pq.top();
    pq.pop();
    return ret;
}
int main() {
    scanf("%d%d", &N, &R);
    for (int n=0, E, C1, V1, CA, CB, CM, VA, VB, VM; n<N; n++) {
        scanf("%d%d%d%d%d%d%d%d%d",&E, &C1, &V1, &CA, &CB, &CM, &VA, &VB, &VM);
        for (int e=0; e<E; e++) {
            if (!C1) {
                free_food+=V1;
            }
            else if (C1<=R) {
                pqs[C1].push(V1);
                if (pqs[C1].size()*C1>R)
                    pqs[C1].pop();
            }
            C1=(1LL*C1*CA+CB)%CM;
            V1=(1LL*V1*VA+VB)%VM;
        }
    }
    for (int r=1; r<=R; r++) {
        while (!pqs[r].empty()) {
            int a=pqs[r]--;
            for (int i=R; i>=r; i--) {
                dp[i]=max(dp[i], dp[i-r]+a);
            }
        }
    }
    printf("%lld", dp[R]+free_food);
    return 0;
}
