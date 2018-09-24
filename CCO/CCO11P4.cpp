#include <bits/stdc++.h>
using namespace std;
int N, r;
map<int, int> num;
int main() {
    scanf("%d%d", &N, &r);
    num[r]=0;
    for (int n=1; n<N; n++) {
        scanf("%d", &r);
        auto m=num.lower_bound(r);
        if (m==num.begin()) {printf("NO"); return 0;}
        num[r]=0;
        prev(num.find(r))->second++;
        if (num[prev(num.find(r))->first]==2) num.erase(prev(num.find(r))->first);
    }
    printf("YES");
}
