//
// Created by 王若璇 on 16/9/8.
//
//lca 朴素法
/*
 * 从根节点开始遍历，求出每个点的深度dis，和父节点fa。
 * 然后进行朴素攀爬法找lca（x，y）*/

//lca 倍增法
/*
 * 首先我们构建一张表p[1,N][1,logN] (这里p[i][j]指的是节点i的第2^j个祖先)
 * p[i][j] = pre[i] // j == 0 时
 * p[ p[i][j-1] ][j-1] // 等于p[i][j-1]的第2^(j-1)的父亲*/

/*---------------------------------------------------------------------------*/
//------------------------------lca倍增法 < nlogn ,logn>---------------------//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <cache_callbacks.h>

#define N 10000100
using namespace std;
int a[N];
int dis[N],dep[N]; //dis为到根节点的距离，dep为深度
int pa[N][20],pre[N];
int pw[N];
struct Edge{
    int b,c;
    int nxt;
}e[N];
int cnt;
int p[N];
void addedge(int a,int b,int c){
    e[cnt].b = b; e[cnt].c = c; e[cnt].nxt = p[a]; p[a] = cnt++;
    e[cnt].b = a; e[cnt].c = c; e[cnt].nxt = p[b]; p[b] = cnt++;

}
void dfs(int u,int f,int deep){ //生成一颗dfs树
    dep[u] = deep;
    pre[u] = f;
    for(int i = p[u];i!=-1;i=e[i].nxt){
        int v = e[i].b;
        int w = e[i].c;
        if(v==f)
            continue;
        dis[v] =dis[u]+w;
        dfs(v,u,deep+1);
    }

}
void make_pa(){ //求倍增祖先
    int i,j;
    memset(pa,-1, sizeof(pa));
    for(i = 1;i<=n;i++)
        pa[i][0] = pre[i];
    for(j = 1;pw[j]<=n;j++){
        for(i = 1;i<=n;i++)
            if(pa[i][j-1]!=-1)
                pa[i][j] = pa[pa[i][j-1]][j-1];
    }
}
int lca(int x,int y){
    int i,log = 0;
    if(dep[x]<dep[y])
        swap(x,y);
    while (pw[log+1]<=dep[x])
        log++;
    for(i = log;i>=0;i--){
        if(dep[x]-pw[i]>=dep[y])
            x = pa[x][i];
    }
    if(x==y)
        return x;
    for(i = log;i>=0;i--){
        if(pa[x][i]!=-1&&pa[x][i]!=pa[y][i])
            x = pa[x][i],y = pa[y][i];
    }
    return pre[x];
}
//-----------------------------lca上的rmq----------------------
//询问路径最大，最小值
//注意： dis[u] 为v－>u 的边权
int mx[N][20];
int tlog[N];
void make_rmq(){
    int i,j;
    memset(mx,-1, sizeof(mx));
    for(i = 1;i<=n;i++)
        mx[i][0] = dis[i];
    for(j = 1;pw[j]<n;j++){
        for(i = 1;i<=n;i++){
            if(pa[i][j-1]!=-1)
                mx[i][j] = max(mx[i][j-1],mx[pa[i][j-1]][j-1]);
        }
    }
}
int get_rmq(int x,int f){
    if(x==f)
        return -1;
    int len = dep[x] - dep[f];
    int k = tlog[len];
    int idx = x;
    for(int j = tlog[len-pw[k]];j>=0;j--){
        if(pw[j]&(len-pw[k]))
            idx = pa[idx][j];
    }
    return max(mx[x][k],mx[idx][k]);
}
void init(){
    for(int i = 0;i<=20;i++){
        pw[i] = (1<<i);
    }
    tlog[0] = -1;
    for(int i = 1;i<=50000;i++){
        tlog[i] = (i&(i-1))?tlog[i-1]:tlog[i-1]+1;
    }
}
int main(){
    int i,j,a,b,c;
    while (scanf("%d%d",&n,&m)!=EOF){
        init();
        for(int i = 1;i<=n;i++){
            scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,c);
        }
        dfs(1,1,0);
        make_pa();
        while (m--){
            scanf("%d%d",&a,&b);
            int f = lca(a,b);
            printf("%d\n",dis[a]+dis[b]-2*dis[f]);
        }
    }

    return 0;
}


