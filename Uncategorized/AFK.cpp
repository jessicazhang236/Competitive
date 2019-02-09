#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int T, L, W, ans, Distance[53][53];
char grid[53][53];
pii starting_point;
queue<pii> candidates;
int main() {
    scanf("%d", &T);
    for (int t=0; t<T; t++) {
        int carrots=0;
        int crazy_carrots=0;
        scanf("%d%d", &L, &W);
        for (int w=1; w<=W; w++) {
            scanf("%s", grid[w]+1);
            for (int l=1; l<=L; l++) {
                if (grid[w][l]=='C')
                    starting_point=make_pair(w, l);
                else if (grid[w][l]=='W')
                    carrots++;
            }
        }
        if (carrots==0) {
            printf("%s\n", "#notworth");
        }
        else {
        memset(Distance, -1, sizeof(Distance));
        Distance[starting_point.first][starting_point.second]=0;
        candidates.push(starting_point);
        while (!candidates.empty()) {
            pii current=candidates.front();
            candidates.pop();
            if (grid[current.first][current.second]=='W'&&Distance[current.first][current.second]<60) {
                printf("%d\n", Distance[current.first][current.second]);
                crazy_carrots+=1;
                break;
            }
            else {
                if (Distance[current.first][current.second]<60) {
                    if (grid[current.first][current.second]!='X') {
                    if (current.first+1<=W&&Distance[current.first+1][current.second]==-1) {
                        Distance[current.first+1][current.second]=Distance[current.first][current.second]+1;
                        candidates.push(make_pair(current.first+1,current.second));
                    }
                    if (current.first-1>=1&&Distance[current.first-1][current.second]==-1) {
                        Distance[current.first-1][current.second]=Distance[current.first][current.second]+1;
                        candidates.push(make_pair(current.first-1,current.second));
                    }
                    if (current.second+1<=L&&Distance[current.first][current.second+1]==-1) {
                        Distance[current.first][current.second+1]=Distance[current.first][current.second]+1;
                        candidates.push(make_pair(current.first,current.second+1));
                    }
                    if (current.second-1>=1&&Distance[current.first][current.second-1]==-1) {
                        Distance[current.first][current.second-1]=Distance[current.first][current.second]+1;
                        candidates.push(make_pair(current.first,current.second-1));
                    }
                    }
                }
                else {
                    printf("%s\n", "#notworth");
                    crazy_carrots+=1;
                    break;
                }
            }
        }
        if (crazy_carrots==0)
                printf("%s\n", "#notworth");
        }
        while (!candidates.empty())
            candidates.pop();
    }
    return 0;
}
