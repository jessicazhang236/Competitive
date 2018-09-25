#include <bits/stdc++.h>
using namespace std;
int x_1, y_1, x_2, y_2, x_3, y_3;
int main() {
    scanf("%d%d%d%d%d%d", &x_1, &y_1, &x_2, &y_2, &x_3, &y_3);
    int Min=(x_2-x_1)*(x_2-x_1)+(y_2-y_1)*(y_2-y_1);
    Min=min(Min, min((x_3-x_1)*(x_3-x_1)+(y_3-y_1)*(y_3-y_1), (x_3-x_2)*(x_3-x_2)+(y_3-y_2)*(y_3-y_2)));
    printf("%d", Min);
}
