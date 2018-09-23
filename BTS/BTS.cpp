#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, J, ans;
bool check;
set<int> way;
vector<pii> paths;
bool compare(pii a, pii b) {
    return a.first<b.first;
}
int main() {
    scanf("%d%d%d", &N, &M, &J);
	for (int m=0, p, t; m<M; m++) {
        scanf("%d%d", &p, &t);
        paths.emplace_back(t, p);
	}
	sort(paths.begin(), paths.end(), compare);
    int cur=0;
    int i=0;
    way.emplace(0);
    while (cur+J<N&&i<paths.size()) {
        way.emplace(paths[0].second);
        cur=max(cur, paths[0].second);
        i++;
    }
    if (i<paths.size())
        printf("%d", paths[i].first);
    else
        printf("-1");
}
