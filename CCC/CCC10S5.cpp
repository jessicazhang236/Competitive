#include <bits/stdc++.h>
using namespace std;
const int MAXN=1028, MAXX=2504;
string S;
int X, cnt=1, tree[MAXN], leaf[MAXX][2], dp[MAXN][MAXX];
void solve(int i) {
    if (!tree[i]) {
        solve(i<<1);
        solve(i<<1|1);
        memset(leaf, 0, sizeof leaf);
        for (int x=0; x<=X; x++) {
            for (int w=0; w<=x; w++) {
                for (int j=0; j<=1; j++)
                    leaf[x][j]=max(leaf[x][j], min((1+w)*(1+w), dp[i<<1|j][x-w]));
            }
        }
        for (int x=0; x<=X; x++) {
            for (int w=0; w<=x; w++)
                dp[i][x]=max(dp[i][x], leaf[w][0]+leaf[x-w][1]);
        }
    }
    else {
        for (int s=0; s<=X; s++) dp[i][s]=tree[i]+s;
    }
}
bool isNum(char a) {
    if (a-'0'>=0&&a-'9'<=0) return true;
    return false;
}
int main() {
    getline(cin, S);
    scanf("%d", &X);
    for (int i=0; i<S.length(); i++) {
        if (S[i]==' ') continue;
        else if (S[i]=='(') cnt<<=1;
        else if (S[i]==')') {
            cnt>>=1;
        }
        else {
            int r=i;
            while (isNum(S[r+1])) r++;
            tree[cnt]=atoi(S.substr(i, r+1-i).c_str());
            i=r;
            cnt++;
        }
    }
    solve(1);
    printf("%d", dp[1][X]);
}
