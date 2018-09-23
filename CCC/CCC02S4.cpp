#include <bits/stdc++.h>
using namespace std;
int M, Q, c, Time[104], DP[104], group[104];
string names[104];
deque<int> num;
int main() {
    scanf("%d%d", &M, &Q);
    memset(DP, 0x3f, sizeof DP);
    for (int q=1; q<=Q; q++) cin>>names[q]>>Time[q];
    DP[1]=Time[1];
    DP[0]=0;
    group[1]=1;
    for (int q=2; q<=Q; q++) {
        int Max=0;
        for (int m=1; m<=min(q, M); m++) {
            int prev=DP[q];
            DP[q]=min(DP[q], DP[q-m]+max(Max, Time[q-m+1]));
            Max=max(Max, Time[q-m+1]);
            if (DP[q]<prev)
                group[q]=m;
        }
    }
    printf("Total Time: %d\n", DP[Q]);
    while (Q>0) {
        num.push_back(group[Q]);
        Q-=group[Q];
    }
    while (!num.empty()) {
        int a=num.back();
        num.pop_back();
        for (int i=1; i<=a; i++) printf("%s ", names[i+c].c_str());
        c+=a;
        printf("\n");
    }
}
