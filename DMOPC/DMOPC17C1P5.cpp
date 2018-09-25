#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> trio;
typedef pair<int, int> pii;
int N, Q, pos, val[1000004], BIT[1000004], ans[1000004];
vector<int> adj[1000004];
vector<trio> queries;
deque<pii> process;
bool compare(trio a, trio b) {
    if (get<0>(a)!=get<0>(b))
        return get<0>(a)<get<0>(b);
    return get<1>(a)<get<1>(b);
}
void update (int i, int val) {
    while (i<1000001) {
        BIT[i]+=val;
        i+=i&-i;
    }
}
int query (int i) {
    int ans=0;
    while (i>0) {
        ans+=BIT[i];
        i-=i&-i;
    }
    return ans;
}
int rangeSum (int l, int r) {
    return query(r)-query(l-1);
}
int main() {
    scanf("%d%d", &N, &Q);
    for (int n=1; n<=N; n++) scanf("%d", &val[n]);
    for (int q=1, l, r; q<=Q; q++) {scanf("%d%d", &l, &r); queries.emplace_back(l, r, q);}
    sort(queries.begin(), queries.end(), compare);
    process.push_back({1000002, 0});
    for (int n=1; n<=N; n++) {
        while (process.back().first<val[n]) process.pop_back();
        adj[process.back().second].push_back(n);
        process.push_back({val[n], n});
    }
    for (auto a: queries) {
        int m=get<0>(a);
        int n=get<1>(a);
        int p=get<2>(a);
        while (pos<m) {
            for (int v: adj[pos]) update(v, 1);
            pos++;
        }
        ans[p]=rangeSum(m, n);
    }
    for (int q=1; q<=Q; q++) printf("%d\n", ans[q]);
}
