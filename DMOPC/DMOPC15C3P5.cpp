#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int A[40], N, M;
unordered_map<ll, ll> val;
ll ans;
int main(){
    scanf("%d%d", &N, &M);
    for(int n=0, a; n<N; ++n){
        scanf("%d",&a);
        A[n]=a;
    }
    for(int m=0, a; m<M; ++m){
        scanf("%d",&a);
        A[m+N]=-a;
    }
    int mid=N+M>>1;
    for(int i=0;i<(1<<mid);i++){
        ll tot=0LL;
        for (int m=0; m<mid; m++) {
            if (i&(1<<m)) tot+=A[m];
        }
        val[tot]++;
    }
    int rt=N+M-mid;
    for (int i=0; i<(1<<rt); i++) {
        ll tot=0LL;
        for (int r=0; r<rt; r++) {
            if (i&(1<<r)) tot+=A[mid+r];
        }
        ans+=val[-tot];
    }
    printf("%lld", ans-1);
}
