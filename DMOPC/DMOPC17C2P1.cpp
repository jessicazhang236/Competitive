#include <bits/stdc++.h>
using namespace std;
string S;
int len;
bool check(string a) {
    for (int m=0; m<=a.length()/2; m++) {
        if (a[m]!=a[a.length()-m-1]) return false;
    }
    return true;
}
int main() {
    cin>>S;
    for (int i=1; i<=S.length()/2; i++) {
        if (check(S.substr(0, i))) {
            for (int j=i; j<S.length(); j++) {
                if (S.substr(0, i)==S.substr(j, j+i)) len=i;
            }
        }
    }
    printf("%d", len);
}
