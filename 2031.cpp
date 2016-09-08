//
// Created by 王若璇 on 16/6/23.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
const double eps = 1e-6;
const int max_n = 110;
struct Cell{
    double x,y,z,r;
    Cell(){}
    Cell(double _x,double _y,double _z,double _r){
        x = _x;
        y = _y;
        z = _z;
        r = _r;
    }
};
double getDis(Cell a,Cell b){
    double disc = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
    if(disc<a.r+b.r+eps){
        return 0;
    } else{
        return disc-a.r-b.r;
    }
}
int par[max_n];
void init(int n){
    for(int i = 0;i<=n;i++){
        par[i] = i;
    }
}
int findx(int x){
    if(x==par[x]){
        return x;
    } else{
        return par[x] = findx(par[x]);
    }
}
void unionx(int a,int b){
    a = findx(a);
    b = findx(b);
    if(a!=b){
        par[a] = b;
    }

}
bool samex(int a,int b){
    return findx(a)==findx(b);
}
struct Edge{
    int from,to;
    double dis;
    bool operator<(const Edge &a) const {
        return dis>a.dis;
    }
    Edge(){}
    Edge(int _from,int _to,double _dis){
        from = _from;
        to = _to;
        dis = _dis;
    }
};
priority_queue<Edge> pq;
int main(){
    vector<Cell> ve;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){
        if(n==0){
            break;
        }

        ve.clear();
        while (!pq.empty()){
            pq.pop();
        }
        init(n);
        for(int i = 0;i<n;i++){
            double x,y,z,r;
            cin>>x>>y>>z>>r;
            ve.push_back(Cell(x,y,z,r));
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                double dis = getDis(ve[i],ve[j]);
                pq.push(Edge(i,j,dis));
            }
        }
        int num = 0;
        double ans = 0;
        while (!pq.empty()&&num<n-1){
            Edge now = pq.top();
            pq.pop();
            if(!samex(now.from,now.to)){
                unionx(now.from,now.to);
                ans+=now.dis;
                num++;
            }
        }
       // cout<<ans<<endl;
        printf("%.3lf\n",ans);
    }

    return 0;
}