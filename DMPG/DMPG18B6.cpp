#include <bits/stdc++.h>
using namespace std;
int N, K, ans=1;
vector<int> cards;
int main() {
    scanf("%d%d", &N, &K);
    for (int n=1, a; n<=N; n++) {
        scanf("%d", &a);
        cards.push_back(a);
    }
    sort(cards.begin(), cards.end());
    int lst=cards[N-1];
    for (int n=N-2; n>=0; n--) {
        if (cards[n]<=lst-K) {
            ans++;
            lst=cards[n];
        }
    }
    printf("%d", ans);
}
