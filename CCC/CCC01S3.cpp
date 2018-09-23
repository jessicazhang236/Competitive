#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
char point_A, point_B;
int edges, ans, adj_mat[30][30];
bool visited[30];
int main() {
    while() {
        scanf("%c%c", &point_A, &point_B);
        if (point_A=='*')
            break;
        else {
            edges++;
            int a=(int)point_A-87;
            int b=(int)point_B-87;
            adj_mat[a][b]=1;
            adj_mat[b][a]=1;
        }
    }

}
