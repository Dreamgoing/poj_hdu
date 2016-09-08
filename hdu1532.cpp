//
// Created by 王若璇 on 16/9/6.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define N 300
#define M 500
using namespace std;
int pre[N],path[N];
bool vis[N];
int cnt = 0;
const int inf = 0x3f3f3f3f;
struct Edge{
    int b,c;
    int next;
}e[M];
int p[N];
void addedge(int a,int b,int c){
    e[cnt].b = b;e[cnt].c = c;
    e[cnt].next = p[a];
    p[a] = cnt++;
    e[cnt].b = a;
    e[cnt].c = 0;
    e[cnt].next = p[b];
    p[b] = cnt++;
}
void init(){
    memset(p,-1, sizeof(p));
}
bool spfa(int s,int t,int n){
    int i,u;
    queue<int> q;
    q.push(s);
    //cout<<"ok"<<endl;
    memset(vis,0, sizeof(vis));
    while (!q.empty()){
        u = q.front();
        q.pop();
        for(i=p[u];i!=-1;i=e[i].next){
            int v = e[i].b;
            if(e[i].c>0&&!vis[v]){
                pre[v] = u;
                path[v] = i;
                vis[v] = true;
                q.push(v);
                if(v==t){
                    return 1;
                }
            }
        }
    }
    return 0;
}
int es(int s,int t,int n){
    int i,aug,maxflow=0;
    while (spfa(s,t,n)){
        aug = inf;
        for(i=t;i!=s;i=pre[i])
            aug = min(aug,e[path[i]].c);
        for(i=t;i!=s;i=pre[i])
            e[path[i]].c-=aug,e[path[i]^1].c+=aug;
        maxflow+=aug;
    }
    return maxflow;
}
int main(){
    int n,m;
    while (scanf("%d%d",&m,&n)!=EOF){
        cnt = 0;
        init();
        for(int i =0;i<m;i++){
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            addedge(x,y,c);
        }
        int res = es(1,n,n);
        printf("%d\n",res);
    }
    return 0;
}
