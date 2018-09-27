/*#include <bits/stdc++.h>
using namespace std;
const int MAXN=5004;
int N, Q, R[2*MAXN], C[2*MAXN];
short d[MAXN][MAXN];
long long area (int q) {
    //(xl, yt) to (xr, yb)+val:
    vector<int> x, y;
    unordered_map<int, int> cmprs_x, cmprs_y;
    long long ans=0LL, l=0LL, h=0LL;
    for (int n=1, xl, xr, yt, yb; n<=N; n++) {
        xl=C[n]+q;
        xr=C[N+n]-q;
        yt=R[n]+q,
        yb=R[N+n]-q;
        x.push_back(xl);
        x.push_back(xr+1);
        y.push_back(yt);
        y.push_back(yb+1);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    for (int k=1; k<=x.size(); k++) cmprs_x[x[k-1]]=k;
    for (int k=1; k<=y.size(); k++) cmprs_y[y[k-1]]=k;
    memset(d, 0, sizeof d);
    for (int n=1, xl, xr, yt, yb; n<=N; n++) {
        xl=C[n]+q;
        xr=C[N+n]-q;
        yt=R[n]+q,
        yb=R[N+n]-q;
        d[cmprs_x[xl]][cmprs_y[yt]]--;
        d[cmprs_x[xl]][cmprs_y[yb+1]]++;
        d[cmprs_x[xr+1]][cmprs_y[yt]]++;
        d[cmprs_x[xr+1]][cmprs_y[yb+1]]--;
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
    scanf("%d", &N);
    for (int n=1; n<=N; n++) scanf("%d%d%d%d", &C[n], &R[n], &C[N+n], &R[N+n]);
    printf("%lld", area(0)-area(1));
}*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN=5004;
int N, x[2*MAXN], y[2*MAXN];
map<int, map<int, int>> cx, cy;
//map<int, int> cmprs_x, cmprs_y;
vector<int> vx, vy;
long long perimeter(map<int, map<int, int>> m) {
    map<int, int> a;
    long long ans=0LL;
    bool st=true;
    int lst=-1, c=0;
    for (auto i: m) {
        if (st) {
            lst=i.first;
            st=false;
        }
        ans+=(i.first-lst)*c;
        c=0;
        int s=0;
        for (auto j: i.second) a[j.first]+=j.second;
        for (auto k: a) {
            if (k.second==0) continue;
            if (s==0) c++;
            s+=k.second;
            if (s==0) c++;
        }
        lst=i.first;
    }
    return ans;
}
int main() {
	scanf("%d", &N);
/*	for (int n=1, xl, xr, yt, yb; n<=N; n++) {
        xl=x[n];
        xr=x[N+n];
        yt=y[n];
        yb=y[N+n];
        vx.push_back(xl);
        vx.push_back(xr);
        vy.push_back(yt);
        vy.push_back(yb);
    }
	sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    for (int k=1; k<=x.size(); k++) cmprs_x[vx[k-1]]=k;
    for (int k=1; k<=y.size(); k++) cmprs_y[vy[k-1]]=k;*/
    for (int n=1, xl, xr, yt, yb; n<=N; n++) {
        scanf("%d%d%d%d", &xl, &yt, &xr, &yb);
        //reverse signs here if WA
        cx[xl][yt]++;
        cx[xl][yb]--;
        cx[xr][yt]--;
        cx[xr][yb]++;
        cy[yt][xl]++;
        cy[yt][xr]--;
        cy[yb][xl]--;
        cy[yb][xr]++;
    }
	printf("%lld\n", perimeter(cx)+perimeter(cy));
	return 0;
}
