#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+4;
int N, M, st, last, lst[MAXN], nxt[MAXN], pre[MAXN];
vector<int> num;
deque<int> lis;
char cmd;
int main() {
    scanf("%d%d", &N, &M);
    for (int n=1; n<=N; n++) {
        lst[n]=n?n-1:N;
        nxt[n]=n!=N?n+1:0;
    }
    for (int m=1, x, y; m<=M; m++) {
        scanf(" %c%d%d", &cmd, &x, &y);
        if (cmd=='A') {
            if (x==lst[y]) continue;
            lst[nxt[x]]=lst[x];
            nxt[lst[x]]=nxt[x];
            nxt[lst[y]]=x;
            lst[x]=lst[y];
            nxt[x]=y;
            lst[y]=x;
        }
        else if (cmd=='B') {
            if (x==nxt[y]) continue;
            lst[nxt[x]]=lst[x];
            nxt[lst[x]]=nxt[x];
            lst[nxt[y]]=x;
            nxt[x]=nxt[y];
            lst[x]=y;
            nxt[y]=x;
        }
    }
    for (int n=1; n<=N; n++) {
        if (!lst[n]) {
            last=st=n;
            break;
        }
    }
    num.push_back(0);
    for (int n=st; n; n=nxt[n]) {
        if (n>num.back()) {
            pre[n]=num.back();
            num.push_back(n);
        }
        else {
            int i=lower_bound(num.begin(), num.end(), n)-num.begin();
            num[i]=n;
            pre[n]=num[i-1];
        }
    }
    printf("%d\n", N-num.size()+1);
    for (int n=num.back(); n; n=pre[n]) lis.push_front(n);
    int rt=1;
    for (int n=0; n<lis.size(); rt++) {
        if (rt<lis[n]) printf("A %d %d\n", rt, lis[n]);
        else if (rt==lis[n]) n++;
    }
    for (; rt<=N; rt++) {
        if (rt>lis.back()) {
            printf("B %d %d\n", rt, lis.back());
            lis.push_back(rt);
        }
    }
}
