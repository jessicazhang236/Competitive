#include <bits/stdc++.h>
using namespace std;
string S, T, line="0";
int Q;
int main() {
    cin>>S;
    cin>>T;
    line+=S;
    if (S.length()==T.length()) {
        scanf("%d", &Q);
        for (int q=1, a; q<=Q; q++) {
            scanf("%d", &a);

        }
        return 0;
    }
    for (int i=1; i<line.length(); i++) {
        if (line[i]=='0') line+=S;
        else line+=T;
        if (line.length()>1000000) break;
    }
    scanf("%d", &Q);
    for (int q=1, a; q<=Q; q++) {
        scanf("%d", &a);
        a--;
        printf("%c\n", line[a]);
    }
    //cout<<line.substr(0, 10);
}

