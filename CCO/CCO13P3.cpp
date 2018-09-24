#include <bits/stdc++.h>
using namespace std;
const int MAXN=400004;
typedef long long ll;
ll cnt;
int N, d, len[MAXN], group[MAXN];
vector<int> adj[MAXN];
void DFS(int cur, int src) {
    group[cur]=1;
    for (int i: adj[cur]) {
        if (i!=src) {
            DFS(i, cur);
            if (len[i]+len[cur]+1>d) {
                d=len[i]+len[cur]+1;
                cnt=1LL*group[i]*group[cur];
            }
            else if (len[i]+len[cur]+1==d) cnt+=1LL*group[i]*group[cur];
            if (len[i]+1>len[cur]) {
                len[cur]=len[i]+1;
                group[cur]=group[i];
            }
            else if (len[i]+1==len[cur]) group[cur]+=group[i];
        }
    }
}
int main() {
    scanf("%d", &N);
    for (int n=1, a, b; n<N; n++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(1, 0);
    printf("%d %lld", d+1, cnt);
}
/*
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN=400004;
int N, lp[MAXN], start, slp[MAXN], par[MAXN], dist[MAXN], d, root, group[MAXN];
ll ans, sum;
vector<int> adj[MAXN];
priority_queue<pii> num;
bool vis[MAXN];
void DFS(int cur, int src) {
    vis[cur]=true;
    for (int i: adj[cur]) {
        if (i!=src&&!vis[i]) {
            DFS(i, cur);
            if (lp[i]+1>lp[cur]) {slp[cur]=lp[cur]; lp[cur]=lp[i]+1;}
            else if (lp[i]+1>slp[cur]) slp[cur]=lp[i]+1;
        }
    }
    d=max(d, lp[cur]+slp[cur]);
}
void DFS2 (int cur, int src) {
    for (int i: adj[cur]) {
        if (i!=src) {
            par[i]=par[cur];
            dist[i]=dist[cur]+1;
            DFS2(i, cur);
            if (dist[i]==lp[par[i]]) group[par[i]]++;
        }
    }
}
int main() {
    scanf("%d", &N);
    for (int n=1, a, b; n<N; n++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int n=1; n<=N; n++) {
        if (adj[n].size()==1) {
            start=n;
            break;
        }
    }
    DFS(start, 0);
    for (int n=1; n<=N; n++) {
        if ((d%2)) {
            if (lp[n]+slp[n]==d&&lp[n]-slp[n]<=1) root=n;
        }
        else {
            if (lp[n]==slp[n]&&lp[n]+slp[n]==d) root=n;
        }
    }
    for (int i: adj[root]) {
        par[i]=i;
        DFS2(i, root);
        if (!group[i]) num.push({lp[i], 1});
        else num.push({lp[i], group[i]});
    }
    pii p=num.top();
    num.pop();
    if (num.empty()) ans=1LL*p.second*(p.second-1)/2LL;
    else {
        pii p2=num.top();
        num.pop();
        if (p2.first==p.first) {
            ll choose=p.second+p2.second;
            while (!num.empty()) {
                p2=num.top();
                num.pop();
                if (p2.first!=p.first) break;
                choose+=p2.second;
            }
            ans=1LL*choose*(choose-1LL)/2LL;
        }
        else {
            ll choose=p2.second;
            while (!num.empty()) {
                pii p3=num.top();
                num.pop();
                if (p3.first!=p2.first) break;
                choose+=p3.second;
            }
            ans=1LL*p.second*choose;
        }
    }
    printf("%d %lld", d+1, ans);
}
/*

void operator += (vector<T> &V, T t) {
    V.push_back(t);
}

int N, len[400002], cnt[400002];
//longest distance to node, and number of this distance
vector<int> adj[400002];
ll dia, num;

void dfs(int u=1, int par=0) {
    len[u] = 0;
    cnt[u] = 1;
    for(int v: adj[u]) {
        if(v == par) continue;
        dfs(v, u);
        if(len[u] + len[v] + 1 > dia){
            dia = len[u] + len[v] + 1;
            num = 1LL * cnt[u] * cnt[v];
        } else if(len[u] + len[v] + 1 == dia) {
            num += 1LL * cnt[u] * cnt[v];
        }
        if(len[v] + 1> len[u]) {
            len[u] = len[v] + 1;
            cnt[u] = cnt[v];
        } else if(len[v] + 1 == len[u]) {
            cnt[u] += cnt[v];
        }
    }
}

int main() {
    dfs();
    printf("%lld %lld", dia + 1, num);
}*/
