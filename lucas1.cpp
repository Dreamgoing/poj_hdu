//
// Created by 王若璇 on 16/9/8.
//

//n<=1e9  m<=1e9 p<=1e6 (p很小，m，n很大！)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <cmath>
#include <stack>
using namespace std;
typedef long long ll;
ll fac[100086];
ll n,m,mod;
void init(){
    fac[0] = 1;
    for(ll i = 1;i<=mod;i++){
        fac[i] = fac[i-1]*i%mod;
    }
}
ll mul(ll a,ll k){
    ll ret = 1;
    for(;k;k>>=1){
        if(k&1)
            ret = (ret*a)%mod;
        a = (a*a)%mod;
    }
    return ret;
}
ll cm(ll n,ll m){
    if(m>n)
        return 0;
    // (a/b) mod p = a * b^(p-2) mod c
    ll res = fac[n]*mul(fac[n-m]*fac[m]%mod,mod-2)%mod;
    return res;
}
ll lucas(ll n,ll m){
    ll ans = 1,a,b;
    while (n&&m){
        a = n%mod;
        b = m%mod;
        ans = ans*cm(a,b)%mod;
        n/=mod;
        m/=mod;
    }
    return ans;
}
int main(){
    while (scanf("%lld%lld%lld",&n,&m,&mod)!=EOF){
        init();
        ll ans = lucas(n,m);
        printf("%lld\n",ans);

    }
}
