//
// Created by 王若璇 on 16/9/8.
//

#include <iostream>
#include <algorithm>
#include <cache_callbacks.h>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <map>

#define N 10001
using namespace std;

int xlike[N][N],ylike[N][N];
int xrank[N][N],yrank[N][N];
int xmat[N],ymat[N]; //匹配

bool find(int x,int y){
    if(ymat[y]==-1){
        xmat[x] = y;
        ymat[y] = x;
        return 1;
    }
    int tx = ymat[y];
    if(yrank[y][tx]>yrank[y][x]){
        xmat[x] = y;
        ymat[y] = x;
        int ty = xlike[tx][xrank[tx][y]+1];
        if(!find(tx,ty)) return 0;
        return 1;
    } else{
        for(int i = xrank[x][y]+1;i<n;i++){
            int ty = xlike[x][i];
            if(!find(x,ty)) continue;
            return 1;
        }
        return 0;
    }
}
bool stable_match(){
    memset(xmat,-1, sizeof(xmat));
    memset(ymat,-1, sizeof(ymat));
    for(int i = 0;i<n;i++){
        if(!find(i,xlike[i][0]))
            return 0;
    }
    return 1;
}

int main(){
    int i,j;
    while (scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&xlike[i][j]);
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&ylike[i][j]);
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                xrank[i][xlike[i][j]] = j;
                yrank[i][ylike[i][j]] = j;
            }
        }
        if(!stable_match())
            puts("Impossible");
        else{
            for(i = 0;i<n;i++){
                printf("%d %d\n",i,xmat[i]);2222222
            }
        }
    }
    return 0;
}
