#include <bits/stdc++.h>
using namespace std;
int S;
char p, c;
int main() {
    scanf("%d", &S);
    scanf(" %c", &p);
    for (int i=2; i<=S; i++) {
        scanf("%c", &c);
        if (c==p) {
            printf("No");
            return 0;
        }
        else p=c;
    }
    printf("Yes");
}
