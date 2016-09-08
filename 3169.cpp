//
// Created by 王若璇 on 16/5/31.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int max_n = 1100;
const int max_v = 11000;
const int inf = 0x3f3f3f3f;
struct Edge{
    int from;
    int to;
    int cost;
}es[max_v];
int d[max_n];
int g[max_n][max_n];
int tol;
int n,m;
struct Edge{
    int from;
    int to;
    int cost;
}es[max_v];
void addEdge(int a,int b,int c){
    es[tol].from = a;
    es[tol].to = b;
    es[tol].cost = c;
    tol++;
}
void shortest_path(int s){
    for(int i = 0;i<=n;i++){
        d[i] = inf;
    }
    d[s] = 0;
    int times = 0;
    bool update = true;
    while (times<n&&update){
        update = false;
        for(int i = 0;i<m;i++){
            Edge now = es[i];
            if(d[now.from]!=inf&&d[now.to]>d[now.from]+now.cost){

                d[now.to] = d[now.from]+now.cost;
                //cout<<now.to<<" "<<d[now.to]<<endl;
                update = true;
            }
        }
        times++;
    }
    if(d[n]==inf){
        cout<<-2<<endl;
        return;
    }
    if(times==n){
        cout<<-1<<endl;
    } else{
        cout<<d[n]<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int ml,md;

    while (cin>>n>>ml>>md){
        int a,b,c;
        tol = 0;
        m = ml+md;
        for(int i = 0;i<ml;i++){
            cin>>a>>b>>c;
            addEdge(a,b,c);
            //g[a][b] = c;
        }
        for(int i = 0;i<md;i++){
            cin>>a>>b>>c;
            addEdge(b,a,-c);
            //g[a][b] = -c;
        }
        /*for(int i = 1;i<n;i++){
            if(g[i][i+1]==0){
                addEdge(i,i+1,0);
                m++;
            }
        }*/
        //shortest_path(1);


    }


    return 0;
}