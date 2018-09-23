#include <bits/stdc++.h>
using namespace std;
int L, N;
string s;
int main() {
    scanf("%d", &L);
    for (int l=0; l<L; l++) {
        vector<string> order;
        unordered_map<string, int> names;
        scanf("%d", &N);
        for (int n=0; n<N; n++) {
            cin >> s;
            order.push_back(s);
        }
        order.insert(order.begin(), order[order.size()-1]);
        names[order[0]]=0;
        int Max=0;
        for (int n=1; n<=N; n++) {
            if (!names[order[n]]&&order[n]!=order[0]) {
                    names[order[n]]=names[order[n-1]]+1;
                    if (names[order[n]]>Max) Max=names[order[n]];
            }
        }
        printf("%d\n", 10*(N-2*Max));
    }
}
