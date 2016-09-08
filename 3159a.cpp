//
// Created by 王若璇 on 16/5/31.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int max_n = 30030;
const int max_v = 150000;
const int inf = 0x3f3f3f3f;

int d[max_n];
//int c[max_n][max_n];
int n,m;
int head[max_n];
bool vis[max_n];
int Q[max_n];
struct Edge{
    int to;
    int cost;
    int next;

};
Edge es[max_v];
int tol;
void add(int a,int b,int v){
    es[tol].to = b;
    es[tol].cost = v;
    es[tol].next = head[a];
    head[a] = tol++;
}
void spfa(int start,int n){
    int top = 0;
    for(int v = 1;v<=n;v++){
        if(v==start){
            Q[top++] = v;
            vis[v] = true;
            d[v] = 0;
        } else{
            vis[v] = false;
            d[v] = inf;
        }
    }
    while (top!=0){
        int u = Q[--top];
        vis[u] = false;
        for(int i = head[u];i!=-1;i=es[i].next){
            int v = es[i].to;
            if(d[v]>d[u]+es[i].cost){
                d[v] = d[u]+es[i].cost;
                if(!vis[v]){
                    vis[v] = true;
                    Q[top++] = v;
                }
            }
        }
    }
}



int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    while (scanf("%d%d",&n,&m)!=EOF){
        //memset(vis,0, sizeof(vis));
        memset(head,-1,sizeof(head));
        tol = 0;
        while (m--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
        }
        spfa(1,n);
        //cout<<d[n]<<endl;
        printf("%d\n",d[n]);



        //cout<<dijstra(1,n)<<endl;
    }
    return 0;
}