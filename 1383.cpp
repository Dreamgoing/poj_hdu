//
// Created by 王若璇 on 16/8/30.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int max_n = 1100;
char mp[max_n][max_n];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;
bool vis[max_n][max_n];
bool ok[max_n][max_n];
int d[max_n][max_n];
pair<int,int> pos;
pair<int,int> kpos;
bool cheak1(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=m;
}
int bfs(){
    queue<pair<int,int> >qu;
    while (!qu.empty()){
        qu.pop();
    }
    qu.push(pos);
    d[pos.first][pos.second] = 0;
    int ans = 0;
    while (!qu.empty()){
        pair<int,int> now = qu.front();
        qu.pop();
        ok[now.first][now.second] = true;
        if(vis[now.first][now.second]){
            continue;
        }
        if(ans<=d[now.first][now.second]){
            ans = d[now.first][now.second];
            kpos = now;
        }
        vis[now.first][now.second] = true;
        int tmpx,tmpy;
        for(int i = 0;i<4;i++){
            tmpx = now.first+dx[i];
            tmpy = now.second+dy[i];
            if(mp[tmpx][tmpy]=='.'&&cheak1(tmpx,tmpy)&&!vis[tmpx][tmpy]){
                qu.push(make_pair(tmpx,tmpy));
                d[tmpx][tmpy] = d[now.first][now.second]+1;
            }
        }
    }
    return ans;
}
int main(){
    int t;
    int res = 0;
    scanf("%d",&t);
    while (t--){
        scanf("%d%d",&m,&n);
        memset(ok,0, sizeof(ok));
        res = 0;
        for(int i = 1;i<=n;i++){
            scanf("%s",mp[i]+1);
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(!ok[i][j]&&mp[i][j]=='.'){
                    memset(vis,0, sizeof(vis));
                    pos.first = i;
                    pos.second = j;
                    bfs();
                    memset(vis,0, sizeof(vis));
                   // cout<<pos.first<<" "<<pos.second<<endl;
                   // cout<<kpos.first<<" "<<kpos.second<<endl;
                    pos=kpos;
                    res = max(res,bfs());
                }
            }
        }
        printf("Maximum rope length is %d.\n",res);
    }
    return 0;
}