#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int Q;
vector<ll> num;
ll K, M, N;
string cvt(ll a) {
    string s="";
    while (a) {
        int i=a%10;
        char m=i+'0';
        s=m+s;
        a/=10;
    }
    return s;
}
bool check(ll a) {
    string s=cvt(a);
    string s2=s;
    reverse(s.begin(), s.end());
    if (s==s2&&(a%K)==0) return 1;
    else return 0;
}
ll cat1(ll a) {
    ll b=a;
    while (b) {
        a*=10LL;
        a+=(b%10);
        b/=10;
    }
    return a;
}
ll cat2(ll a) {
    ll b=a/10LL;
    while (b) {
        a*=10LL;
        a+=(b%10);
        b/=10;
    }
    return a;
}
int main() {
    scanf("%d%lld", &Q, &K);
    for (int i=1; i<1000000; i++) {
        ll a=cat1(ll(i));
        if (check(a)) {
            num.push_back(a);
            //printf("%d\n", a);
        }
        ll b=cat2(ll(i));
        if (check(b)) num.push_back(b);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    for (int q=1; q<=Q; q++) {
        scanf("%lld%lld", &M, &N);
        int tot=upper_bound(num.begin(), num.end(), N)-lower_bound(num.begin(), num.end(), M);
        printf("%d\n", tot);
    }
}
