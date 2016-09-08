//
// Created by 王若璇 on 16/5/30.
//
//简单的差分约束 注意最长路还是最短路
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int max_n = 30030;
const int max_v = 150000;
const int inf = 0x3f3f3f3f;
struct Edge{
    int from;
    int to;
    int cost;
}es[max_v];
int d[max_n];
int v,e;
void bellman_ford(int s){
    for(int i = 0;i<=v;i++){
        d[i] = inf;
    }
    d[s]=0;
    int times = 0;
    while (times<e-1){
        bool update = false;
        for(int i = 0;i<e;i++){
            Edge now = es[i];
            //cout<<d[2]<<endl;
            //cout<<d[now.from]<<" "<<d[now.to]<<" "<<es[i].from<<" "<<es[i].to<<" "<<es[i].cost<<endl;
            if(d[now.from]!=inf&&d[now.to]>d[now.from]+now.cost){
                d[now.to] = d[now.from]+now.cost;
                update = true;
            }
        }
        times++;
        if(!update){
            break;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while (cin>>n>>m){
        //memset(d,0, sizeof(d));
        e = m;
        v = m;
        for(int i = 0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            es[i].from = a;
            es[i].to = b;
            es[i].cost = c;
        }
        bellman_ford(1);
        int ans = 0;
        for(int i = 1;i<=n;i++){
            ans = max(ans,d[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
