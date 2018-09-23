#include <bits/stdc++.h>
using namespace std;
int H, k, l, h=1000000, m, cnt;
vector<int> dist;
inline int calc(int r) {
    int ans=H;
    int len=2*r;
    for (int h=0; h<H; h++) {
        if (dist[h]>dist[0]+len) break;
        cnt=1;
        int cover=dist[h]+r;
        for (int i=h+1; i<H; i++) {
            if (dist[i]+len>=dist[h]+1000000) break;
            if (dist[i]>cover) {
                cnt++;
                cover=dist[i]+len;
            }
        }
        ans=min(ans, cnt);
    }
    return ans;
}
int main() {
    scanf("%d", &H);
    for (int h=0, m; h<H; h++) {
        scanf("%d", &m);
        dist.push_back(m);
    }
    scanf("%d", &k);
    sort(dist.begin(), dist.end());
    while (l<=h) {
        m=l+h>>1;
        if (calc(m)>k) l=m+1;
        else h=m-1;
    }
    printf("%d", l);
}
