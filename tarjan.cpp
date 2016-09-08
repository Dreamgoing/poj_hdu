//
// Created by 王若璇 on 16/9/8.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#define clr(x) memset(x,0,sizeof(x))
const int max_n = 100010;
struct node{
    int to;
    int next;
}q[max_n];
int head[max_n];
int tot;
int n,m;
void add(int s,int u){
    q[tot].to = u;
    q[tot].next = head[s];
    head[s] = tot++;
}
int dfn[max_n];
int low[max_n];
int stack[max_n];
int ti,sn,top;
bool instack[max_n];
void tarjan(int u){
    dfn[u] = low[u] = ++ti; //取时间戳
    stack[++top] = u; //当前节点入栈
    instack[u] = true;
    int k,i;
    for(i = head[u];i;i=q[i].next){
        k = q[i].to;
        if(dfn[k]==0){ // k 没有访问过，k是u的子女，（u，k）为树枝边
            tarjan(k);
            if(low[u]>low[k]) // 取子女可以达到的最早时间戳
                low[u] = low[k];
        } else if(instack[k]&&low[u]>dfn[k]){   // k访问过，k是u的祖先，（u，k）是一条回边
            low[u] = dfn[k]; //取回边中可以到达的最早时间戳
        } else;

    }
    if(low[u] == dfn[u]){ //以u为根的强连通分量已经找到
        sn++;
    }
    do{
        k = stack[top--];
        instack[k] = false;
    }while (k!=u);
}
int main(){
    int a,b,i;
    while (scanf("%d%d",&n,&m)!=EOF,n){
        clr(head);
        clr(instack);
        clr(dfn);
        ti = sn = 0;
        tot = 1;
        while (m--){
            scanf("%d%d",&a,&b);
            add(a,b);
        }
        for(int i = 1;i<=n;i++){
            if(dfn[i]==0){
                tarjan(i);
            }
        }
        if(sn>1){
            printf("No\n");
        } else{
            printf("Yes\n");
        }
    }
    return 0;
}
