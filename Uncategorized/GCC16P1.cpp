#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, A, C, ans, diffA[1000001], diffC[1000001];
vector<pii> anime, work;
vector<int> S;
unordered_map<int, int> compress;
int main() {
    scanf("%d%d%d", &N, &A, &C);
    for (int a=0, ai, bi; a<A; a++) {
        scanf("%d%d", &ai, &bi);
        anime.push_back(make_pair(ai, bi+1));
        S.push_back(ai);
        S.push_back(bi+1);
    }
    for (int c=0, ci, di; c<C; c++) {
        scanf("%d%d", &ci, &di);
        work.push_back(make_pair(ci, di+1));
        S.push_back(ci);
        S.push_back(di+1);
    }
    sort (S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());
    for (int i=0; i<S.size(); i++) {
        compress[S[i]]=i;
    }
    for (int a=0, ai, bi; a<A; a++) {
        ai=anime[a].first;
        bi=anime[a].second;
        diffA[compress[ai]]++;
        diffA[compress[bi]]--;
    }
    for (int c=0, ci, di; c<C; c++) {
        ci=work[c].first;
        di=work[c].second;
        diffC[compress[ci]]++;
        diffC[compress[di]]--;
    }
    for (int b=1;b<S.size(); b++) {
        diffA[b]+=diffA[b-1];
        diffC[b]+=diffC[b-1];
    }
    for (int i=0; i<S.size()-1; i++) {
        if (diffA[i]>0&&!diffC[i])
            ans+=S[i+1]-S[i];
    }
    printf("%d",ans);
}
