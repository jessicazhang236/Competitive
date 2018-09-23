#include <bits/stdc++.h>
using namespace std;
bool check;
string s, grid[12][12];
int val[12][12];
bool checkNum(string a) {
    int b=(int)(a[0]-'0');
    if (b>=0&&b<=9)
        return true;
    return false;
}
string Clear(string a) {
    for (int i=0; i<a.length(); i++) {
        if (a[i]=='+') a.erase(i, 1);
    }
    return a;
}
int main() {
    for (int i=1; i<=10; i++) {
        for (int j=1; j<=9; j++) {
            cin >> s;
            grid[i][j]=s;
            if (checkNum(s))
                val[i][j]=atoi(s.c_str());
            else
                val[i][j]=-1;
        }
    }
	while (!check) {
        check=true;
        for (int i=1; i<=10; i++) {
            for (int j=1; j<=9; j++) {
                if (val[i][j]==-1) {
                    string s1=Clear(grid[i][j]);
                    int u=0;
                    for (int m=0; m<=s1.length()-2; m+=2) {
                        int v=val[(int)(s1[m]-'A')+1][s1[m+1]-'0'];
                        if (v==-1) {
                            u=-1;
                            break;
                        }
                        else u+=v;
                    }
                    if (u!=val[i][j]) {
                        check=false;
                        val[i][j]=u;
                    }
                }
            }
        }
	}
	for (int i=1; i<=10; i++) {
        for (int j=1; j<=9; j++) {
            if (val[i][j]==-1)
                printf("* ");
            else
                printf("%d ", val[i][j]);
        }
        printf("\n");
	}
}
