#include <bits/stdc++.h>
using namespace std;
const int MAX=1000004;
int N, M;
double dist[MAX];
vector<int> adj[MAX];
int main() {
    scanf("%d%d", &N, &M);
    for (int m=1, i, j; m<=M; m++) {scanf("%d%d", &i, &j); adj[i].push_back(j);}
    dist[1]=1;
    for (int n=1; n<=N; n++) {
        for (int i: adj[n])
            dist[i]+=dist[n]/adj[n].size();
    }
    for (int n=1; n<=N; n++) {
        if (adj[n].size()==0) printf("%.9f\n", dist[n]);
    }
}
