//
// Created by 王若璇 on 16/9/8.
//

/*组合树取模
 * 求C(n+m,n)%p的值，保证p为素数
 * n<=1e9  m<=1e6 p<=1e9 （m很小，p很大）
 *
 *
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll mul(ll a,ll k,ll mod){
    ll ret = 1;
    for(;k;k>>=1){
        if(k&1)
            ret = (ret*a)%mod;
        a=(a*a)%mod;
    }
    return ret;
}
ll cm(ll n,ll m,ll mod){
    ll i,ans = 1,a,b;
    //(a/b) mod p = a*b^(p-2) mod c
    for(i = 0;i<m;i++){
        a = (n-i)%mod;
        b = (m-i)%mod;
        ans = ans*(a*mul(b,mod-2,mod)%mod)%mod;
    }
    return ans;
}
ll lucas(ll n,ll m,ll p){
    if(m==0)
        return 1;
    return (cm(n%p,m%p,p)*lucas(n/p,m/p,p) )%p;
}
int main(){
    ll n,m,p;
    int ;
    scanf("%d",&t);
    while (t--){
        scanf("%lld%lld%lld",&n,&m,&p);
        ll ans = lucas(n,m,p);
        printf("%lld\n",ans);
    }
    return 0;
}

