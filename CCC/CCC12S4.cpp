#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, st, lst;
queue<pii> state;
bool vis[2097155];
int main() {
    scanf("%d", &N);
    while (N) {
        memset(vis, 0, sizeof vis);
        st=lst=0;
        for (int n=0, a; n<N; n++) {
            scanf("%d", &a);
            a--;
            st|=n<<(a*3);
            lst|=n<<(n*3);
        }
        state.push({st, 0});
        while (!state.empty()) {
            pii cur=state.front();
            state.pop();
            if (cur.first==lst) {
                printf("%d\n", cur.second);
                goto out;
            }
            if (vis[cur.first]) {
                //printf("continued on %d\n", cur.first);
                continue;
            }
            for (int n=0; n<N; n++) {
                int pos=(cur.first>>(n*3))&7;
                //printf("%d\n", pos);
                int nxt=cur.first;
                //printf("nxt initial: %d\n", nxt);
                nxt&=~(7<<(n*3));
                //printf("nxt: %d\n", nxt);
                bool lf=1;
                bool rt=1;
                for (int i=0; i<n; i++) {
                    int mv=(cur.first>>(i*3))&7;
                    //printf("cur.first: %d mv: %d\n", cur.first, mv);
                    if (mv==pos-1) lf=0;
                    else if (mv==pos) {
                        lf=rt=0;
                        break;
                    }
                    else if (mv==pos+1) rt=0;
                }
                //printf("lf: %d rt: %d\n", lf, rt);
                if (lf&&pos>0) {
                    state.push({nxt|((pos-1)<<(n*3)), cur.second+1});
                    //printf("%d move to left\n",  n);
                }
                if (rt&&pos<N-1) {
                    state.push({nxt|((pos+1)<<(n*3)), cur.second+1});
                    //printf("%d move to right\n", n);
                }
            }
            vis[cur.first]=1;
            //printf("%d\n", state.size());
        }
        printf("IMPOSSIBLE\n");
        out: scanf("%d", &N);
        while (!state.empty()) state.pop();
    }
}
