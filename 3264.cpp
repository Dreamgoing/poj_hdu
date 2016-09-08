//
// Created by 王若璇 on 16/7/19.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int max_n = 50500;
const int inf = 0x3f3f3f3f;
int mi[max_n][17],mx[max_n][17],w[max_n];
int n,q;
void initrmq(){
    for(int i = 1;i<=n;i++){
        mi[i][0]=mx[i][0]=w[i];
    }
    int m = (int)(log(1.*n)/log(2.0));
    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            mx[j][i] = mx[j][i-1];
            if(j+(1<<(i-1))<=n){
                mx[j][i] = max(mx[j][i],mx[j+(1<<(i-1))][i-1]);
            }
            mi[j][i] = mi[j][i-1];
            if((j+(1<<(i-1)))<=n){
                mi[j][i] = min(mi[j][i],mi[j+(1<<(i-1))][i-1]);
            }

        }
    }
}
int rmqmin(int l,int r){
    int m = (int)(log(1.*(r-l+1))/log(2.0));
    return min(mi[l][m],mi[r-(1<<m)+1][m]);
}
int rmqmax(int l,int r){
    int m = (int)(log(1.*(r-l+1))/log(2.0));
    return max(mx[l][m],mx[r-(1<<m)+1][m]);
}
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    scanf("%d%d",&n,&q);
    memset(mi,inf, sizeof(mi));
    for(int i = 1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    initrmq();
    int l,r;
    while (q--){
        scanf("%d%d",&l,&r);
        //cout<<rmqmax(l,r)-rmqmin(l,r)<<endl;
        printf("%d\n",rmqmax(l,r)-rmqmin(l,r));
    }
    return 0;
}