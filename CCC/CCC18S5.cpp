#include <bits/stdc++.h>
using namespace std;
const int MAXN=100004;
int N, M, P, Q, H[MAXN], V[MAXN], h, v;
long long sum, init;
typedef tuple<int, int, int, int> carrot;
vector<carrot> paths;
bool cmp(carrot a, carrot b) {
    return get<2>(a)<get<2>(b);
}
inline int fndh(int i) {
    if (H[i]!=i) H[i]=fndh(H[i]);
    return H[i];
}
inline void mrgh(int i, int j) {
    H[fndh(i)]=fndh(j);
}
inline int fndv(int i) {
    if (V[i]!=i) V[i]=fndv(V[i]);
    return V[i];
}
inline void mrgv(int i, int j) {
    V[fndv(i)]=fndv(j);
}
int main() {
    scanf("%d%d%d%d", &N, &M, &P, &Q);
    for (int p=1, a, b, c; p<=P; p++) {
        scanf("%d%d%d", &a, &b, &c);
        paths.emplace_back(a, b, c, 1);
        init+=1LL*N*c;
    }
    for (int q=1, a, b, c; q<=Q; q++) {
        scanf("%d%d%d", &a, &b, &c);
        paths.emplace_back(a, b, c, 2);
        init+=1LL*M*c;
    }
    sort(paths.begin(), paths.end(), cmp);
    for (int n=1; n<=N; n++) H[n]=n;
    for (int m=1; m<=M; m++) V[m]=m;
    for (auto m: paths) {
        int a=get<0>(m);
        int b=get<1>(m);
        int c=get<2>(m);
        int flg=get<3>(m);
        if (flg==1) {
            if (fndv(a)!=fndv(b)) {
                mrgv(a, b);
                v++;
                sum+=1LL*(N-h)*c;
            }
        }
        else {
            if (fndh(a)!=fndh(b)) {
                mrgh(a, b);
                h++;
                sum+=1LL*(M-v)*c;
            }
        }
        if (h==N-1&&v==M-1) break;
    }
    printf("%lld", init-sum);
}
