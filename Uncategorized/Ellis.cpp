#include <bits/stdc++.h>
using namespace std;
#define getchar() (*_pinp?*_pinp++:(_inp[fread_unlocked(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;
typedef long long ll;
typedef pair<ll, ll> pll;
const int RN=316;
int N, Q, c, BIT[100004];
set<int> sortA;
ll A[100004], output[100004];
struct trio {
    int First;
    int Second;
    int Third;
    bool operator<(const trio &t) const {
        int f = First/RN, tf = t.First/RN;
        if (f != tf)
            return f < tf;
        return Second<t.Second;
    }
};
vector<trio> queries;
map<int, int> compress;
inline ll query(int x) {
    ll sum=0LL;
    for(;x;x-=x&-x)
        sum+=BIT[x];
    return sum;
}
inline void update(int x, ll val) {
    for(;x<100001;x+=x&-x)
        BIT[x]+=val;
}
inline ll rangeSum(const int &a, const int &b) {
    return query(b)-query(a-1);
}
int main() {
    scan(N);
    for (int n=1; n<=N; n++) {
        scan(A[n]);
        sortA.insert(A[n]);
    }
    for(auto a:sortA)
        compress[a]=++c;
    for (int n=1; n<=N; n++)
        A[n]=compress[A[n]];
    scan(Q);
    for (int q=0, l, r; q<Q; q++) {
        scan(l);
        scan(r);
        queries.emplace_back(trio{l, r, q});
    }
    sort(queries.begin(), queries.end());
    int L=1;
    int R=1;
    ll c=0LL;
    int pre=0;
    update(A[1], 1LL);
    for (int q=0, a, b; q<Q; q++) {
        a=queries[q].First;
        b=queries[q].Second;
        if (a/RN!=pre) {
        memset(BIT, 0, sizeof BIT);
        L=R=a;
        update(A[a], 1LL);
        c=0LL;
        pre=a/RN;
        }
        if (a<L) {
            for (int i=L-1; i>=a; i--) {
                update(A[i],1LL);
                c+=rangeSum(1, A[i]-1);
            }
        }
        if (b>R) {
            for (int i=R+1; i<=b; i++) {
                update(A[i],1LL);
                c+=rangeSum(A[i]+1,100001);
            }
        }
        if (a>L) {
            for (int i=L; i<a; i++) {
                update(A[i], -1LL);
                c-=rangeSum(1, A[i]-1);
            }
        }
        if (b<R) {
            for (int i=R; i>b; i--) {
                update(A[i], -1LL);
                c-=rangeSum(A[i]+1,100001);
            }
        }
    output[queries[q].Third]=c;
    L=a;
    R=b;
    }
    for (int i=0; i<Q; i++)
            printf("%lld\n", output[i]);
    return 0;
}
