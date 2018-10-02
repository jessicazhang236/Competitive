#include <bits/stdc++.h>
using namespace std;
const double epsilon=1e-6;
typedef long long ll;
int N;
ll bit[3][30006];
void upd(int id, ll val) {
    ll v=1LL;
    for (int lvl=0; lvl<3; lvl++) {
        for (int i=id; i<=30001; i+=i&-i)
            bit[lvl][i]+=v;
        v*=val;
    }
}
ll qry(int id, int lvl) {
    ll out=0LL;
    for (int i=id; i; i-=i&-i) out+=bit[lvl][i];
    return out;
}
ll range(int l, int lvl) {
    return qry(30001, lvl)-qry(l, lvl);
}
int main() {
    scanf("%d", &N);
    for (int n=1, x; n<=N; n++) {
        scanf("%d", &x);
        x+=15001;
        upd(x, x);
        double l=1.0, r=30001.0, mid;
        while (fabs(r-l)>epsilon) {
            mid=(l+r)/2.0;
            int k=(int)floor(mid);
            double xl=qry(k, 0)*mid*mid-2.0*qry(k, 1)*mid+qry(k, 2);
            double xr=range(k, 0)*mid*mid-2.0*range(k, 1)*mid+range(k, 2);
            if (xl<xr) l=mid;
            else r=mid;
        }
        printf("%.6f\n", mid-15001);
    }
}
