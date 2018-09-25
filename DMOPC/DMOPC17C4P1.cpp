#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<pii> cuts;
int N, Q, blue, st, lst;
bool cmp(pii a, pii b) {
    if (a.first!=b.first) return a.first<b.first;
    else return a.second<b.second;
}
int main() {
    scanf("%d%d", &N, &Q);
    for (int q=1, x, y; q<=Q; q++) {
        scanf("%d%d", &x, &y);
        cuts.emplace_back(x, y);
    }
    sort(cuts.begin(), cuts.end(), cmp);
    for (int i=0; i<cuts.size(); i++) {
        int x=cuts[i].first;
        int y=cuts[i].second;
        if (x>lst) {
            blue+=(lst-st);
            st=x;
            lst=y;
        }
        else lst=max(y, lst);
    }
    blue+=(lst-st);
    printf("%d %d\n", N-blue, blue);
}
