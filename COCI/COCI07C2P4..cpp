#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAX=100004;
int N, BIT[MAX];
vector<pii> elements;
void update(int m, int val) {
    while (m<100001) {
        BIT[m]+=val;
        m+=m&(-m);
    }
}
int query(int m) {
    int ans=0;
    while (m>0) {
        ans+=BIT[m];
        m-=m&(-m);
    }
    return ans;
}
int rangeSum (int a, int b) {
    return abs(query(b)-query(a-1));
}
int main() {
    scanf("%d", &N);
    for (int n=1, a; n<=N; n++) {
        scanf("%d", &a);
        elements.emplace_back(a, n);
        update(a, 1);
    }
    sort(elements.begin(), elements.end());
    for (int n=1; n<=N; n++) {
        if (n%2==1) {
            printf("%d\n", rangeSum(1, elements[n-1].second));
            update(elements[n-1].second, -1);
        }
        else {
            printf("%d\n", rangeSum(elements[N-n].second, 100001));
            update(elements[N-n].second, -1);
        }
    }
}
