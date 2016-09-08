//
// Created by 王若璇 on 16/9/8.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>

#define N 1000100

//注意：下标从0 开始！！！
int e[N][N]; //连接矩阵
int set[N],cs[N]; //临时变量
int ans[N],num; //保存答案
bool mak;
void clique(int n,int depth,int *u){
    int i,j,v[N],vn;
    if(n){
        if(depth+cs[u[0]]<=num)
            return;
        for(i = 0;i<n+depth-num;i++){
            for(j = i+1,vn = 0;j<n;j++){
                if(e[u[i]][u[j]]) v[vn++] = u[j];
                set[depth] = u[i];
                clique(vn,depth+1,v);
                if(mak)
                    return;
            }
        }
    }else if(depth>num){
        num = depth;
        mak = 1;
        for(i = 0;i<depth;i++)
            ans[i] = set[i];
    }
}
int reclique(int n){
    int vn,v[N],i,j;
    num = 0;
    for(cs[i=n-1];i>=0;i--){
        for(vn=0,j=i+1;j<n;j++)
            if(e[i][j]) v[vn++] = j;
        mak = 0;
        set[0] = i;
        clique(vn,1,v);
        cs[i] = num;
    }
    return num;
}