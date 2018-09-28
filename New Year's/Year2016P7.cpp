#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+4, LN=20;
int N, K, Q, elements[MAXN], L1=1, L[MAXN], R[MAXN], RMQ[LN][MAXN];
deque<int> Max, Min;
inline void build() {
    for (int i=1; i<=19; i++) {
        for (int j=1; j+(1<<i-1)<=N; j++)
            RMQ[i][j]=max(RMQ[i-1][j], RMQ[i-1][j+(1<<i-1)]);
    }
}
int query(int R, int l, int r) {
    if (l==r) return l;
    int len=r-l+1;
    /*if (len==2) {
        if (min(RMQ[0][l], R-l+1)>=min(RMQ[0][l+1], R-l)) return l;
        else return l+1;
    }*/
    int k=(int)floor(log2(len));
    if ((1<<k)==len) k--;
    int m=max(min(RMQ[k][l], R-l+1), min(RMQ[k][r-(1<<k)+1], R-r+(1<<k)));
    if (min(RMQ[k][l], R-l+1)==m) return query(R, l, l+(1<<k)-1);
    else return query(R, r-(1<<k)+1, r);
}
/*inline int query(int l, int r) {
    int m=0;
    int i=-1;
    while (l<=r) {
        if (min(R[l]+l, r+1)-l>m) {
            m=min(R[l], r-l+1);
            i=l;
        }
        //l+=R[l];
        l++;
    }
    return i;
}*/
int main() {
    scanf("%d%d", &N, &K);
    for (int n=1, a; n<=N; n++) {
        scanf("%d", &a);
        elements[n]=a;
        while (!Max.empty()&&Max.back()<a) Max.pop_back();
        Max.push_back(a);
        while (!Min.empty()&&Min.back()>a) Min.pop_back();
        Min.push_back(a);
        while (Max.front()-Min.front()>K) {
            R[L1]=n-L1;
            if (Max.front()==elements[L1]) Max.pop_front();
            if (Min.front()==elements[L1]) Min.pop_front();
            L1++;
        }
        L[n]=n-L1+1;
    }
    for (; L1<=N; L1++) R[L1]=N-L1+1;
    for (int n=1; n<=N; n++) RMQ[0][n]=R[n];
    build();
    scanf("%d", &Q);
    for (int q=1, l, r; q<=Q; q++) {
        scanf("%d%d", &l, &r);
        if (R[l]>=r-l+1) printf("%d %d\n", l, r);
        else {
            int m=query(r, l, r-L[r]);
            if (min(r, m+R[m]-1)-m+1>=L[r]) printf("%d %d\n", m, min(r, m+R[m]-1));
            else printf("%d %d\n", r-L[r]+1, r);
            /*int m=query(r, l, r);
            printf("%d %d\n", m, min(r, m+R[m]-1));*/
        }
    }
}
