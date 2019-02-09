#include <bits/stdc++.h>
using namespace std;
const int MAXL=1e6+4, MAXN=1e5+4;
int T, N, ans, lst, cnt, trie[30][MAXL];
bool check;
string S;
int main() {
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        ans=cnt=0;
        scanf("%d", &N);
        memset(trie, 0, sizeof trie);
        for (int n=1; n<=N; n++) {
            cin>>S;
            check=0;
            lst=0;
            for (int k=0; k<S.length(); k++) {
                if (!check) {
                    ans++;
                    //printf("%c %d\n", S[k], t);
                }
                if (!trie[S[k]-'a'][lst]) {
                    check=1;
                    trie[S[k]-'a'][lst]=++cnt;
                }
                lst=trie[S[k]-'a'][lst];
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
}
