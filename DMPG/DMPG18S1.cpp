#include <bits/stdc++.h>
using namespace std;
char S[100004];
int l, i;
bool check(int ind) {
    if (ind>=l) return 0;
    int cur=S[i++]-'0';
    for (int a=0; a<cur; a++) {
        if (!check(i)) return 0;
    }
    return 1;
}
int main() {
    scanf("%s", S);
    l=strlen(S);
    if (check(0)&&i==l) printf("Valid");
    else printf("Invalid");
}
