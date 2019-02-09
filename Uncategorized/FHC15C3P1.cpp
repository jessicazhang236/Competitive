#include <bits/stdc++.h>
using namespace std;
const double e=1e-6;
typedef pair<int, int> pii;
int T, Xi, Yi, D, N;
bool cmp(pii a, pii b) {
    return atan2((a.second-Yi)*1.0, (a.first-Xi)*1.0)<atan2((b.second-Yi)*1.0, (b.first-Xi)*1.0);
}
int main() {
    scanf("%d", &T);
    for (int t=1, ans; t<=T; t++) {
        ans=0;
        vector<pii> pt, pt2;
        scanf("%d%d%d%d", &Xi, &Yi, &D, &N);
        for (int n=1, x, y; n<=N; n++) {
            scanf("%d%d", &x, &y);
            pt.emplace_back(x, y);
            pt2.emplace_back(x, y);
        }
        sort(pt.begin(), pt.end(), cmp);
        for (int n=0, a; n<N; n++) {
            a=1;
            if ((pt[n].first-Xi)*(pt[n].first-Xi)+(pt[n].second-Yi)*(pt[n].second-Yi)>D*D) continue;
            while (n+1<N&&fabs(atan2(pt[n].second-Yi*1.0, pt[n].first-Xi*1.0)-atan2(pt[n+1].second-Yi*1.0, pt[n+1].first-Xi*1.0))<e) {
                n++;
                if ((pt[n].first-Xi)*(pt[n].first-Xi)+(pt[n].second-Yi)*(pt[n].second-Yi)<=D*D) {
                    a++;
                }
            }
            double X=cos(atan2(pt[n].second-Yi*1.0, pt[n].first-Xi*1.0))*D+Xi;
            double Y=sin(atan2(pt[n].second-Yi*1.0, pt[n].first-Xi*1.0))*D+Yi;
            sort(pt2.begin(),pt2.end(),[=](const pii s, const pii r) {
                return atan2(s.second-Y, s.first-X)<atan2(r.second-Y, r.first-X);
            });
            int st=0, max_b=0;
            for (int i=0, b; i<N; i++) {
                b=1;
                if (fabs(pt2[i].first*1.0-X)<e&&fabs(pt2[i].second*1.0-Y)<e) {st=1; continue;}
                while (i+1<N&&fabs(atan2(pt2[i].second-Y, pt2[i].first-X)-atan2(pt2[i+1].second-Y, pt2[i+1].first-X))<e) {
                    b++;
                    i++;
                }
                max_b=max(b, max_b);
            }
            ans=max(a*(max_b+st), ans);
        }
        printf("Case #%d: %d\n", t, ans);
    }
}
