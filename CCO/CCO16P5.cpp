/*#include <bits/stdc++.h>
using namespace std;
const int MAXK=2004;
int N, M, K, Q, R[MAXK], C[MAXK], flag[MAXK*2];
long long ans;
vector<int> x, y;
unordered_map<int, int> cmprs_x, cmprs_y;
struct line {
    int crt, st, ed, flg;
    line (int a, int b, int c, int d) {
        st=b;
        ed=c;
        crt=a;
        flg=d;
    }
};
bool compare(line l1, line l2) {
    return l1.crt<l2.crt||(l1.crt==l2.crt&&l1.flg>l2.flg);
}
vector<line> lnx, lny;
int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int k=1; k<=K; k++) scanf("%d%d", &R[k], &C[k]);
    scanf("%d", &Q);
    if (!Q) {
        printf("%d", K);
        return 0;
    }
    for (int k=1; k<=K; k++) {
        if (C[k]-Q>0) x.push_back(C[k]-Q);
        if (C[k]+Q<=M) x.push_back(C[k]+Q);
        if (R[k]-Q>0) y.push_back(R[k]-Q+1);
        if (R[k]+Q<=N) y.push_back(R[k]+Q-1);
        if (C[k]-Q>0) lnx.emplace_back(C[k]-Q, max(1, R[k]-Q+1), min(N, R[k]+Q-1), 1);
        if (C[k]+Q<=M) lnx.emplace_back(C[k]+Q, max(1, R[k]-Q+1), min(N, R[k]+Q-1), -1);
        if (R[k]-Q>0) lny.emplace_back(R[k]-Q, max(1, C[k]-Q), min(C[k]+Q, M), 1);
        if (R[k]+Q<=N) lny.emplace_back(R[k]+Q, max(1, C[k]-Q), min(C[k]+Q, M), -1);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(lnx.begin(), lnx.end(), compare);
    sort(lny.begin(), lny.end(), compare);
    x.erase(unique(x.begin(), x.end()), x.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    for (int k=0; k<x.size(); k++) cmprs_x[x[k]]=k;
    for (int k=0; k<y.size(); k++) cmprs_y[y[k]]=k;
    for (int i=0; i<lnx.size()-1; i++) {
        for (int n=cmprs_x[lnx[i].st]; n<=cmprs_x[lnx[i].ed]; n++) flag[n]+=lnx[i].flg;
        if (flag[i]-lnx[i].flg==1&&!flag[i]) {
            ans+=(lnx[i+1].crt-lnx[i].crt+1);
            printf("%d %d\n", lny[i+1].crt, lny[i].crt);
        }
        else if (!(flag[i]-lnx[i].flg)&&flag[i]==1) {
            ans+=(lnx[i+1].crt-lnx[i].crt+1);
            printf("%d %d\n", lny[i+1].crt, lny[i].crt);
        }
    }
    ans+=(lnx[lnx.size()-1].ed-lnx[lnx.size()-1].st+1);
    for (int i=0; i<lny.size()-1; i++) {
        for (int n=cmprs_y[lny[i].st]; n<=cmprs_y[lny[i].ed]; n++) flag[n]+=lny[i].flg;
        if (flag[i]-lny[i].flg==1&&!flag[i]) {
            printf("%d %d\n", lny[i+1].crt, lny[i].crt);
            ans+=(lny[i+1].crt-lny[i].crt+1);
        }
        else if (!(flag[i]-lny[i].flg)&&flag[i]==1) {
            ans+=(lny[i+1].crt-lny[i].crt+1);
            printf("%d %d\n", lny[i+1].crt, lny[i].crt);
        }
    }
    ans+=(lny[lny.size()-1].ed-lny[lny.size()-1].st+1);
    printf("%lld", ans);
}
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXK=2004;
int N, M, K, Q, R[MAXK], C[MAXK], d[2*MAXK][2*MAXK];
long long area (int q) {
    //(xl, yt) to (xr, yb)+val:
    vector<int> x, y;
    unordered_map<int, int> cmprs_x, cmprs_y;
    long long ans=0LL, l=0LL, h=0LL;
    for (int k=1, xl, xr, yt, yb; k<=K; k++) {
        xl=max(1, C[k]-q);
        xr=min(M, C[k]+q);
        yt=min(N, R[k]+q),
        yb=max(1, R[k]-q);
        x.push_back(xl);
        x.push_back(xr+1);
        y.push_back(yt+1);
        y.push_back(yb);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    for (int k=1; k<=x.size(); k++) cmprs_x[x[k-1]]=k;
    for (int k=1; k<=y.size(); k++) cmprs_y[y[k-1]]=k;
    memset(d, 0, sizeof d);
    for (int k=1, xl, xr, yt, yb; k<=K; k++) {
        xl=max(1, C[k]-q);
        xr=min(M, C[k]+q);
        yt=min(N, R[k]+q);
        yb=max(1, R[k]-q);
        d[cmprs_x[xl]][cmprs_y[yt+1]]--;
        d[cmprs_x[xl]][cmprs_y[yb]]++;
        d[cmprs_x[xr+1]][cmprs_y[yt+1]]++;
        d[cmprs_x[xr+1]][cmprs_y[yb]]--;
    }
    for (int i=1; i<x.size(); i++) {
        l=x[i]-x[i-1];
        h=0LL;
        for (int j=1; j<y.size(); j++) {
            d[i][j]=(d[i][j]+d[i-1][j]+d[i][j-1]-d[i-1][j-1]);
            if (d[i][j]) h+=(y[j]-y[j-1]);
        }
        ans+=1LL*l*h;
    }
    return ans;
}
int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int k=1; k<=K; k++) scanf("%d%d", &R[k], &C[k]);
    scanf("%d", &Q);
    printf("%lld", Q?area(Q)-area(Q-1):K);
}
