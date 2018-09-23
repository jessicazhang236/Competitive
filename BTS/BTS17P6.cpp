#include <bits/stdc++.h>
using namespace std;
int N, BIT[100004], order[100004], Max, i, j;
unordered_map<int, int> Index;
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
    return query(b)-query(a-1);
}
int main() {
    scanf("%d", &N);
    for (int n=1, a; n<=N; n++) {
        scanf("%d", &a);
        Index[a]=n;
        update(n, 1);
    }
    for (int n=1, x; n<=N; n++) {
        scanf("%d", &x);
        order[n]=Index[x];
    }
    i=j=Max=1;
    for (int n=2, last=1; n<=N; n++) {
        if (order[n]<order[n-1]) last=n;
        if (n-last+1>Max) {Max=n-last+1; i=last; j=n;}
    }
    printf("%d\n", N-Max);
    for (int n=j+1; n<=N; n++) {
        printf("B %d\n", rangeSum(1, order[n]));
        update(order[n], -1);
    }
    for (int n=i-1, c=0; n>0; n--) {
        printf("F %d\n", rangeSum(1, order[n])+c);
        c++;
        update(order[n], -1);
    }
}
