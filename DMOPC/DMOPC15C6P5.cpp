#include <bits/stdc++.h>
using namespace std;
const int MAXN=3*1e6+4;
int N, K, L1=1, elements[MAXN], L[MAXN], R[MAXN];
long long ans=0LL;
deque<int> Max, Min;
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
    for (int n=1; n<=N; n++) ans+=R[n];
    printf("%lld", ans);
}
