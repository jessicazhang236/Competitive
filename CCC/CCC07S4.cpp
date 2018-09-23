#include <bits/stdc++.h>
using namespace std;
const int MAX=10004;
int N, x, y, dist[MAX];
vector<int> adj[MAX];
int main() {
    scanf("%d", &N);
    scanf("%d%d", &x, &y);
    adj[y].push_back(x);
    while (x&&y) {scanf("%d%d", &x, &y); adj[y].push_back(x);}
    for (int v: adj[N]) dist[v]=1;
    for (int i=N-1; i>0; i--) {
        for (int v: adj[i]) dist[v]+=dist[i];
    }
    printf("%d", dist[1]);
}
