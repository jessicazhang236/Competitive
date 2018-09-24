#include <bits/stdc++.h>
using namespace std;
typedef pair<double, int> pdi;
struct trio{
    int x, y, w;
    trio(int a, int b, int c) {
        x=a;
        y=b;
        w=c;
    }
};
const double epsilon=1e-6, pi=3.1415926535897932384626433832795028842;
int N, ans;
vector<trio> pts;
vector<pdi> sweep;
int main() {
    scanf("%d", &N);
    for (int n=1, a, b, c; n<=N; n++) {
        scanf("%d%d%d", &a, &b, &c);
        pts.push_back(trio(a, b, c));
    }
    for (int n=0; n<N; n++) {
        sweep.clear();
        for (int i=0; i<N; i++) {
            if (i==n) continue;
            double m=atan2(pts[i].y-pts[n].y, pts[i].x-pts[n].x);
            sweep.emplace_back(m, pts[i].w);
            sweep.emplace_back(m+2*pi, pts[i].w);
        }
        sort(sweep.begin(), sweep.end());
        int sum=max(0, pts[n].w);
        for (int l=0, r=0; l<N;) {
            while (r<2*N&&sweep[r].first-sweep[l].first<=pi) sum+=sweep[r++].second;
            ans=max(ans, sum);
            while (l<N&&fabs(sweep[l+1].first-sweep[l].first)<=epsilon) sum-=sweep[l++].second;
            sum-=sweep[l++].second;
        }
    }
    printf("%d\n", ans);
}
