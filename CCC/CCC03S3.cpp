#include <bits/stdc++.h>
using namespace std;
int N, R, C, movement[4][2]={{1,0},{-1,0},{0,1},{0,-1}}, room;
vector<int> sizes;
char flr[30][30];
void DFS(int a, int b) {
    room++;
    flr[a][b]='I';
    for (int i=0;i<4;++i) {
        int m=a+movement[i][0];
        int n=b+movement[i][1];
        if(m>0&&m<=R&&n>0&&n<=C&&flr[m][n]=='.') {
            DFS(m, n);
        }
    }
}
int main() {
    scanf("%d%d%d", &N, &R, &C);;
    for (int r=1; r<=R; r++)
        scanf("%s", flr[r]+1);
    for (int r=1; r<=R; r++) {
        for (int c=1; c<=C; c++) {
            if (flr[r][c]=='.') {
                DFS(r, c);
                sizes.push_back(room);
                room=0;
            }
        }
    }
    sort(sizes.begin(), sizes.end(), greater<int>());
    int i=0;
    for(int s:sizes) {
        N-=s;
        if(N<0) {
            N+=s;
            break;
        }
        ++i;
    }
    printf("%d %s, %d square metre(s) left over", i, i==1?"room":"rooms", N);
}
