//
// Created by 王若璇 on 16/6/1.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int max_n = 200500;
const int inf = 0x3f3f3f3f; //差分约束小于等于最短路,大于等于最长路.
int head[max_n];
int d[max_n];
struct Edge{
    int to;
    int cost;
    int next;
}es[max_n];
int tol = 0;
int up = 0;
int down = 0x3f3f3f3f;
queue<int> qu;
bool vis[max_n];
int n;
void addEdge(int a,int b,int c){
    es[tol].to = b;
    es[tol].cost = c;
    es[tol].next = head[a];
    head[a] = tol++;
}
void spfa(int s,int t){
    for(int i = down;i<=up;i++){
        d[i] = -inf;
    }
    while (!qu.empty()){
        qu.pop();
    }
    qu.push(s);
    d[s] = 0;
    vis[s] = true;
    while (!qu.empty()){
        int u = qu.front();
        qu.pop();
        vis[u] = false;
        for(int i = head[u];i!=-1;i = es[i].next){
            int v = es[i].to;
            if(d[v]<d[u]+es[i].cost){
                d[v] = d[u]+es[i].cost;
                if(!vis[v]){
                    vis[v] = true;
                    qu.push(v);
                }
            }
        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>n){
        memset(head,-1, sizeof(head));
        for(int i = 0;i<n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            addEdge(a-1,b,c);
            up = max(up,b);
            down = min(down,a-1);
        }
        for(int i = down;i<up;i++){
            addEdge(i,i+1,0);
            addEdge(i+1,i,-1);
        }
        spfa(down,up);
        cout<<d[up]-d[down]<<endl;
    }

    return 0;
}