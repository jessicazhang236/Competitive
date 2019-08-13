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
