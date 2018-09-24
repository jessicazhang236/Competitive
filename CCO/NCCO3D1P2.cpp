#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int MAXN=1e4+4;
int N, M[MAXN], ord[MAXN], tmp, ans;
bool vis[MAXN];
vector<pii> id;
int main() {
    scanf("%d", &N);
    for (int n=0; n<N; n++) {
        scanf("%d", &M[n]);
        id.emplace_back(M[n], n);
    }
    sort(id.begin(), id.end());
    tmp=id[0].first;
    for (int n=0; n<N; n++) ord[id[n].second]=n;
    for (int n=0; n<N; n++) {
        if (vis[n]||ord[n]==n) continue;
        int cur=n;
        int Min=0x3f3f3f3f;
        int loop=0;
        while (!vis[cur]) {
            vis[cur]=1;
            ans+=M[cur];
            Min=min(Min, M[cur]);
            cur=ord[cur];
            loop++;
        }
        ans+=min((loop-2)*Min, tmp*(loop+1)+Min);
    }
    printf("%d\n", ans);
}
