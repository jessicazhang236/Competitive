#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> rnk;
const int MAXN=1e6+4;
int N, num[MAXN], x, r, k;
char cmd;
#define getchar() (*_pinp?*_pinp++:(_inp[fread_unlocked(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;
unordered_map<int, int> id;
int main() {
    scan(N);
    for (int n=1; n<=N; n++) {
        cmd=getchar();
        if (cmd=='N') {
            scan(x);
            scan(r);
            num[x]=r;
            id[r]=x;
            rnk.insert(r);
        }
        else if (cmd=='M') {
            scan(x);
            scan(r);
            id[num[x]]=0;
            rnk.erase(num[x]);
            num[x]=r;
            id[r]=x;
            rnk.insert(r);
        }
        else {
            scan(k);
            int ans=id[*rnk.find_by_order(k-1)];
            printf("%d\n", ans);
        }
    }
}
