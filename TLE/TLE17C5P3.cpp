#include <bits/stdc++.h>
using namespace std;
int N;
typedef pair<int, int> pii;
vector<int> non;
vector<int> mod[204][204];
bool unit[204], red[204], prime[204];
int main() {
    scanf("%d", &N);
    for (int i=1; i<=N-1; i++) {
        for (int j=1; j<=N-1; j++) {
            if (i*j%N==1) {unit[i]=red[i]=red[j]=unit[j]=1;}
            int k=i*j%N;
            mod[k][i].push_back(j);
            mod[k][j].push_back(i);
        }
    }
    printf("Units:\n");
    for (int n=0; n<=N-1; n++) {
        if (unit[n]) printf("%d\n", n);
        else (non.push_back(n));
    }
    int s=non.size();
    for (int i=0; i<s; i++) {
        for (int j=0; j<s; j++) {
            int a=non[i];
            int b=non[j];
            int k=a*b%N;
            red[k]=1;
        }
    }
    printf("Irreducibles:\n");
    for (int n=1; n<=N-1; n++) {
        if (!red[n]) printf("%d\n", n);
        else {
            for (int i=1; i<=N-1; i++) {
                if (unit[i]) continue;
                if (mod[n][i].empty()) continue;
                for (int j=1; j<=N-1; j++) {
                    if (mod[n][j].empty()) continue;
                    if (i==j) continue;
                    if (!mod[j][i].empty()) continue;
                    for (int k=0; k<mod[n][j].size(); k++) {
                        if (mod[mod[n][j][k]][i].empty()) prime[i]=1;
                    }
                }
            }
        }
    }
    printf("Primes:\n");
    for (int n=1; n<=N-1; n++) {
        if (!unit[n]&&!prime[n]) printf("%d\n", n);
    }
}
