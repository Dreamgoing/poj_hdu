//
// Created by 王若璇 on 16/6/1.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int max_n = 200500;
/*S[ai - 1] <= S[bi] - ci ;
S[i] <= S[i - 1] + 1
S[i - 1] <= S[i]*/
struct Edge{
    int from;
    int to;
    int cost;
}es[max_n];
int d[max_n];
//int g[max_n][max_n];
int tol;
int n,m;
int up = 0;
int down = 0x3f3f3f3f;
const int inf = 0x3f3f3f3f;
void addEdge(int a,int b,int c){
    es[tol].from = a;
    es[tol].to = b;
    es[tol].cost = c;
    tol++;
}
void shortest_path(int s){
    for(int i = down;i<=up;i++){
        d[i] = inf;
    }
    d[s] = 0;
    int times = 0;
    bool update = true;
    while (update){
        update = false;
        for(int i = 0;i<tol;i++){
            Edge now = es[i];
            if(d[now.from]!=inf&&d[now.to]>d[now.from]+now.cost){

                d[now.to] = d[now.from]+now.cost;
                //cout<<now.to<<" "<<d[now.to]<<endl;
                update = true;
            }
        }
        times++;
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>n){
        int a,b,c;
        up = 0;
        down = 0x3f3f3f3f;
        tol = 0;
        for(int i = 0;i<n;i++){
            cin>>a>>b>>c;
            addEdge(b,a-1,-c);
            up = max(up,b);
            down = min(down,a-1);
        }
        m = n;
        for(int i = down;i<up;i++){
            addEdge(i,i+1,1);
            addEdge(i+1,i,0);
            //addEdge(i+1,down,0);
            m+=2;
        }
        for(int i = down;i<=up;i++){
            addEdge(up+2,i,0);
        }
        shortest_path(up+2);
        cout<<d[up]-d[down]<<endl;

    }


    return 0;
}