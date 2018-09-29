#include <bits/stdc++.h>
using namespace std;
int N, M, W, ants[20], dis1[104], dis2[104];
vector<int> adj[104];
queue<int> people, ant;
bool vis1[104], vis2[104];
int main() {
    scanf("%d%d", &N, &M);
    for (int m=0, a, b; m<M; m++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%d", &W);
    for (int w=1, x; w<=W; w++) scanf("%d", &ants[w]);
    for (int w=1; w<=W; w++) {
        int a=ants[w];
        ant.push(a);
        dis1[a]=0;
    }
    people.push(1);
    dis2[1]=0;
    while (!ant.empty()) {
        int a=ant.front();
        ant.pop();
        vis1[a]=true;
        for (int i: adj[a]) {
            if (!vis1[i]) {
                ant.push(i);
                dis1[i]=dis1[a]+4;
            }
        }
    }
    while (!people.empty()) {
        int a=people.front();
        people.pop();
        vis2[a]=true;
        for (int i: adj[a]) {
            if (!vis2[i]) {
                dis2[i]=dis2[a]+1;
                if(dis1[i]<=dis2[i]) continue;
                people.push(i);
            }
        }
    }
    if (!vis2[N]) printf("sacrifice bobhob314");
    else printf("%d", dis2[N]);
}
