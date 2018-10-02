#include <bits/stdc++.h>
using namespace std;
int N, a, b;
string name, s;
int main() {
    scanf("%d", &N);
    cin>>name;
    for (int n=1; n<=N; n++) {
        scanf("%d/%d", &a, &b);
        cin>>s;
        if (a<=b) {
            printf("N\n");
            continue;
        }
        else {
            for (int i=0; i<s.length(); i++) {
                if (s[i]!=name[i]) {
                    printf("N\n");
                    goto out;
                }
            }
            printf("Y\n");
        }
        out: continue;
    }
}
