#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+6;
int N, H;
ll dp[MAXN], pos[MAXN];
deque<int> Q;
double f(int k, int j) {
    return 1.0*(dp[j]-dp[k]+pos[j+1]*pos[j+1]-pos[k+1]*pos[k+1])/(2.0*(pos[j+1]-pos[k+1]));
}
int main() {
    scanf("%d%d", &N, &H);
    for (int n=1; n<=N; n++) scanf("%lld", &pos[n]);
    Q.push_back(0);
    for (int n=1; n<=N; n++) {
        while(Q.size()>=2&&f(Q[0], Q[1])<=pos[n]) Q.pop_front();
        dp[n]=dp[Q.front()]+H+(pos[n]-pos[Q[0]+1])*(pos[n]-pos[Q[0]+1])*1LL;
        //printf("%lld %d %d %d\n", dp[Q.front()], pos[n], pos[Q.front()], n);
        while(Q.size()>=2&&f(Q[Q.size()-2], Q[Q.size()-1])>=f(Q[Q.size()-1], n)) Q.pop_back();
        Q.push_back(n);
    }
    printf("%lld", dp[N]);
}
