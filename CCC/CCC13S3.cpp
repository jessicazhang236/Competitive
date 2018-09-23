#include <bits/stdc++.h>
using namespace std;
int T, G, score[5][5], cnt, match[5][5];
void calc(int a[5][5], int b) {
    if (b==6) {
        int ans=0;
        for (int i=1; i<=4; i++) ans+=max(0, a[T][i]);
        bool check=false;
        for (int i=1; i<=4; i++) {
            int sum=0;
            if (i==T) continue;
            for (int j=1; j<=4; j++) sum+=max(0, a[i][j]);
            if (sum>=ans) check=true;
        }
        if (!check) cnt++;
    }
    else {
        int c[5][5];
        memcpy(c, a, sizeof c);
        int first=0, second=0;
        vector<int> carrot;
        for (int i=1; i<=4; i++) {
            int sum=0;
            for (int j=1; j<=4; j++) {
                if (a[i][j]==-1) sum++;
            }
            if (sum>1) carrot.push_back(i);
        }
        for (int i=0; i<carrot.size(); i++) {
            for (int j=i+1; j<carrot.size(); j++) {
                if (!match[carrot[i]][carrot[j]]) {
                    first=carrot[i], second=carrot[j];
                    goto out;
                }
            }
        }
        out:
        match[first][second]=match[second][first]=1;
        c[first][second]=1, c[second][first]=1;
        calc(c, b+1);
        int d[5][5];
        memcpy(d, a, sizeof d);
        d[first][second]=0, d[second][first]=3;
        calc(d, b+1);
        int e[5][5];
        memcpy(e, a, sizeof e);
        e[first][second]=3, e[second][first]=0;
        calc(e, b+1);
        match[first][second]=match[second][first]=0;
    }
}
int main() {
    scanf("%d%d", &T, &G);
    memset(score, -1, sizeof score);
    for (int g=1, a, b, sa, sb; g<=G; g++) {
        scanf("%d%d%d%d", &a, &b, &sa, &sb);
        if (sa>sb) {
            score[a][b]=3;
            score[b][a]=0;
        }
        else if (sa<sb) {
            score[a][b]=0;
            score[b][a]=3;
        }
        else {
            score[a][b]=1;
            score[b][a]=1;
        }
        match[a][b]=match[b][a]=1;
    }
    calc(score, G);
    printf("%d", cnt);
}
