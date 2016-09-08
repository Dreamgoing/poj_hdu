//
// Created by 王若璇 on 16/6/23.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
const int max_n = 5500;
const double eps = 1e-6;
struct Point{
    double x,y;
    Point(){ }
    Point(int _x,int _y){
        x = _x;
        y = _y;
    }
    Point operator-(const Point &a)const{
        return Point(x-a.x,y-a.y);
    }
    Point operator+(const Point &a)const {
        return Point(x+a.x,y+a.y);
    }
}ul,lr;
struct Line{
    Point a,b;
    Line(){}
    Line(Point _a,Point _b){
        a = _a;
        b = _b;
    }

};
double xmulti(Point p1,Point p2,Point p0){
    //若结果为正,则<p0,p1>在<p0,p2>的顺时针方向
    //若结果为0,则<p0,p1> <p0,p2>共线
    //若结果为负,则<p0,p1>在<p0,p2>的逆时针方向
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
map<int,int> res;
vector<Line> lve;
void binarysearch(int l,int r,Point x){
   // int mid = (l+r)/2;
    while (l<r-1){
        int mid = (l+r)/2;
        double dis = xmulti(lve[mid].b,x,lve[mid].a);
       // cout<<dis<<" --  "<<mid<<endl;
        if(dis<-eps){
            r = mid;
        } else{
            l = mid;
        }
    }
    //cout<<"l =="<<l<<endl;
    res[l]++;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x1,y1,x2,y2;

    while (cin>>n){
        if(n==0){
            break;
        }
        cin>>m;
        lve.clear();
        res.clear();
        cin>>ul.x>>ul.y>>lr.x>>lr.y;
        lve.push_back(Line(ul,Point(ul.x,lr.y)));
        for(int i = 0;i<n;i++){
            int u,l;
            cin>>u>>l;
            lve.push_back(Line(Point(u,ul.y),Point(l,lr.y)));
        }
        lve.push_back(Line(Point(lr.x,ul.y),lr));
        for(int i = 0;i<m;i++){
            Point tmp;
            cin>>tmp.x>>tmp.y;
            binarysearch(0,lve.size()-1,tmp);
        }
        //binarysearch(0,lve.size(),Point(2,8));
        for(int i = 0;i<=n;i++){
            cout<<i<<": "<<res[i]<<endl;
        }
        cout<<'\n';

    }
    return 0;
}