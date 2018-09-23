#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> BBST;
BBST ranking;
int T, val, num;
long long ans;
int main() {
    scanf("%d", &T);
    for (int t=1, a; t<=T; t++) {
        scanf("%d", &a);
        ranking.insert(a);
        num=ranking.order_of_key(*ranking.upper_bound(a));
        ans+=num;
    }
    double av=1.0*ans/T;
    printf("%.2f", av+1.00);
}
