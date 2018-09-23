#include <bits/stdc++.h>
using namespace std;
int N;
double Min=1000000000.0;
vector<int> pos;
vector<double> dist;
int main() {
    scanf("%d", &N);
    for (int n=1, a; n<=N; n++) {
        scanf("%d", &a);
        pos.push_back(a);
    }
    sort(pos.begin(), pos.end());
    for (int i=0; i<N-1; i++) {
        dist.push_back((pos[i+1]+pos[i])*1.0/2.0);
    }
    for (int i=0; i<dist.size()-1; i++) {
        //printf("%.1f\n", dist[i]);
        Min=min(Min, dist[i+1]-dist[i]);
    }
    printf("%.1f", Min);
}
