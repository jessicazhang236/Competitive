#include <bits/stdc++.h>
using namespace std;
int N;
char a, b;
vector<char> adj[30];
set<char> ans[30];
bool vis[30], check[30], exist[30];
void DFS (int cur) {
    vis[cur]=true;
    for (auto i: adj[cur]) {
        if (!vis[i-'A']) {
            DFS(i-'A');
            for (char a: ans[i-'A']) ans[cur].insert(a);
        }
    }
}
int main() {
    scanf("%d", &N);
    for (int n=1; n<=N; n++) {
        scanf(" %c contains %c", &a, &b);
        exist[a-'A']=true;
        if (b<'a') {adj[a-'A'].push_back(b); check[a-'A']=true; exist[b-'A']=true;}
        else ans[a-'A'].insert(b);
    }
    for (int i=0; i<26; i++) {
        memset(vis, false, sizeof vis);
        if (check[i]) DFS(i);
    }
    for (int i=0; i<26; i++) {
        if (exist[i]) {
            printf("%c = {", i+'A');
            int c=0;
            for(char j: ans[i]) {
                if(c>0)
                    printf(",");
                printf("%c", j);
                c++;
            }
            printf("}\n");
        }
    }
}
