#include <bits/stdc++.h>
using namespace std;
int c;
char r;
string mod (char m) {return string("(")+"c"+m+"r";}
int main() {
    scanf("%c", &r);
    while (r!=')') {
        if (r=='c'||r=='('||r=='r'||r=='x'||r==' ') scanf("%c", &r);
        else {printf("%s ", mod(r).c_str()); c++; scanf("%c", &r);}
    }
    printf("x");
    for (int m=0; m<c; m++) printf(")");
}
