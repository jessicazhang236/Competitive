#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int, int> group;
int N, Q, mass[100002], BIT[20002], output[100002];
vector<group> queries;
bool compare(group a, group b) {
    if (get<0>(a)/(int)sqrt(N)!=get<0>(b)/(int)sqrt(N))
        return get<0>(a)/(int)sqrt(N)<get<0>(b)/(int)sqrt(N);
    return get<1>(a)<get<1>(b);
}
void update(int x, int val) {
    for(;x<20002;x+=x&-x)
        BIT[x]+=val;
}
int query(int x) {
    int sum=0;
    for(;x>0;x-=x&-x)
        sum+=BIT[x];
    return sum;
}
int rangeSum(int a, int b) {
    return query(b)-query(a-1);
}
int main() {
    scanf("%d", &N);
    for (int n=0; n<N; n++) {
        scanf("%d", &mass[n]);
    }
    scanf("%d", &Q);
    for (int q=0, l, r, k; q<Q; q++) {
        scanf("%d%d%d", &l, &r, &k);
        queries.emplace_back(l,r,k,q);
    }
    sort(queries.begin(), queries.end(), compare);
    int L=0;
    int R=0;
    update(mass[0], mass[0]);
    for (int q=0, a, b; q<Q; q++) {
        a=get<0>(queries[q]);
        b=get<1>(queries[q]);
        while (L>a) {
            update(mass[L], mass[--L]);
        }
        while (R<b) {
            update(mass[R], mass[++R]);
        }
        while (L<a) {
            update(mass[L++], -mass[L]);
        }
        while (R>b) {
            update (mass[R--], -mass[R]);
        }
    output[get<3>(queries[q])]=rangeSum(get<2>(queries[q]), 20002);
    L=a;
    R=b;
    }
    for (int q=0; q<Q; q++) {
        printf("%d\n", output[q]);
    }
    return 0;
}
