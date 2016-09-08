//
// Created by 王若璇 on 16/9/8.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <stack>
#include <queue>

#define N 10000000
using namespace std;
const int max_n = 1000100;
const int inf = 0x3f3f3f3f;
struct Edge{
    int b,c,w,nxt;
}e[max_n];
int p[N];
int cnt;
int pre[N],path[N],dis[N];
bool vis[N];
void addedge(int a,int b,int c,int w){
    e[cnt].b = b; e[cnt].c = c; e[cnt].w = w; e[cnt].nxt = p[a]; p[a] = cnt++;
    e[cnt].b = a; e[cnt].c = 0; e[cnt],w = -w; e[cnt].nxt = p[b]; p[b] = cnt++;
}
bool spfa(int s,int t,int n){
    int i,u;
    queue<int> q;
    for(int i = 0;i<=n;i++){
        dis[i] = inf;
    }
    memset(vis,0, sizeof(vis));
    dis[s] = 0;
    q.push(s);
    while (!q.empty()){
        u = q.front();
        q.pop();
        vis[u] = 0;
        for(i = p[u];i!=-1;i=e[i].nxt){
            int v = e[i].b;
            int c = e[i].c;
            int w = e[i].w;
            if(c>0&&dis[v]>dis[u]+w){
                dis[v] = dis[u]+w;
                pre[v] = u;
                path[v] = i;
                if(!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    if(dis[t] == inf){
        return 0;
    }
    return 1;
}
int mfmc(int s,int t,int n){
    int i;
    int aug,maxflow = 0,maxcost = 0;
    while (spfa(s,t,n)){
        aug = inf;
        for(i = t;i!=s;i=pre[i]){
            if(aug>e[path[i]].c)
                aug = e[path[i]].c;
        }
        for(i = t;i!=s;i=pre[i]){
            e[path[i]].c -=aug;
            e[path[i]^1].c+=aug;
        }
        maxcost+=dis[t]*aug;
        maxflow+=aug;
    }
    return maxcost;
}