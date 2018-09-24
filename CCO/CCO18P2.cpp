#include <bits/stdc++.h>
using namespace std;
bool arr[104][104];
int main() {
    arr[2][1]=arr[2][2]=arr[2][3]=1;
    for (int n=3; n<=100; n++) {
        if (n%2) arr[n][1]=1;
        else arr[n][3]=1;
    }
    printf("100\n");
    for (int n=2; n<=100; n++) {
        for (int i=1; i<=100-n+1; i++) {
            if (!arr[n][i]) printf("100 ");
            else printf("1 ");
        }
        printf("\n");
    }
}
