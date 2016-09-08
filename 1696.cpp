//
// Created by 王若璇 on 16/8/3.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int max_n = 100;
const double eps = 1e-6;
int now = 0;

struct Point{
    double x,y;
    int id;
    Point(){}
    Point(int _id,double _x,double _y){
        id = _id;
        x = _x;
        y = _y;
    }
    /*bool operator<(const Point& p)const{
        Point p0 = ve[now];
        double tmp = xmulti(*this,p,p0);
        if(tmp>eps){
            return true;
        } else if(fabs(tmp)<eps&&getDis(*this,p0)>getDis(p,p0)){
            return true;
        } else{
            return false;
        }
    }*/
};
double getDis(Point p1,Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
double xmulti(Point p1,Point p2,Point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
vector<Point> ve;
bool cmp(const Point& p1,const Point& p2){
    Point p0 = ve[now];
    double tmp = xmulti(p1,p2,p0);
    if(tmp>eps){
        return true;
    } else if(fabs(tmp)<eps&&getDis(p1,p0)<getDis(p2,p0)){
        return true;
    } else{
        return false;
    }

}


vector<int> ans;
int main(){
    int t;
    int n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        //cout<<n<<endl;
        ve.clear();
        ans.clear();
        //ve.push_back(Point(0,0,0));
        for(int i = 0;i<n;i++){
            int id;
            double x,y;
            scanf("%d%lf%lf",&id,&x,&y);
            ve.push_back(Point(i+1,x,y));
            if(ve[i].y<ve[0].y){
                swap(ve[i],ve[0]);
            }
        }
        ans.push_back(0);
        int num = 0;
        now = 0;
        ans.push_back(ve[0].id);
        num++;
        while (num<n){
            now = num-1;
            sort(ve.begin()+num,ve.end(),cmp);
            ans.push_back(ve[num].id);
            //cout<<num<<"*"<<n<<endl;
            num++;
        }
        printf("%d",num);
        for(int i = 1;i<=num;i++){
            printf(" %d",ans[i]);
        }
        printf("\n");

    }
    return 0;
}
