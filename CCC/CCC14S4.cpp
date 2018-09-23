#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define cmprs compress_remapping_with_hearts_after_it_so_it_is_extra_long_for_the_lols_help_why_do_you_do_this_to_me_i_see
struct line {
    int xl, yl, xr, t;
    line (int a, int b, int c, int d) {
        xl=a;
        yl=b;
        xr=c;
        t=d;
    }
};
int N, T, L[2004];
long long ans;
vector<line> lines;
vector<int> x;
unordered_map<int, int> cmprs;
bool compare (line l1, line l2) {
    return l1.yl<l2.yl||(l1.yl==l2.yl&&l1.t>l2.t);
}
int main() {
    scanf("%d%d", &N, &T);
    for (int n=1, a, b, c, d, e; n<=N; n++) {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        lines.emplace_back(a, b, c, e);
        lines.emplace_back(a, d, c, -e);
        x.push_back(a);
        x.push_back(c);
    }
    sort(all(x));
    sort(all(lines), compare);
    x.erase(unique(all(x)), x.end());
    for (int i=0; i<x.size(); i++)
        cmprs[x[i]]=i;
    for (int n=cmprs[lines[0].xl]; n<cmprs[lines[0].xr]; n++) L[n]+=lines[0].t;
    for(int i=1;i<lines.size();i++) {
        for (int n=0; n<x.size()-1; n++) if (L[n]>=T) ans+=1LL*(x[n+1]-x[n])*(lines[i].yl-lines[i-1].yl);
        for (int n=cmprs[lines[i].xl]; n<cmprs[lines[i].xr]; n++) L[n]+=lines[i].t;
    }
    printf("%lld", ans);
}
