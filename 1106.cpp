//
// Created by 王若璇 on 16/8/3.
//
#include <iostream>
#include <algorithm>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const double eps = 1e-6;
const int max_n = 200;
const double pi = acos(-1.0);
struct Point{
    double x,y;
};
struct Circle{
    Point co;
    double r;
};
double getDis(Point p1,Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
double xmulti(Point p1,Point p2,Point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
Circle c;
bool cmp(const Point& p1,const Point& p2){
    double tmp = xmulti(p1,p2,c.co);
    return tmp>0;
}
vector<Point> ve;
int main(){
    int n;
    while(scanf("%lf%lf%lf",&c.co.x,&c.co.y,&c.r)!=EOF){
        ve.clear();
        scanf("%d",&n);
        //cout<<"n "<<n<<endl;
        if(c.r<0){
            break;
        }
        for(int i = 0;i<n;i++){
            Point tmp;
            scanf("%lf%lf",&tmp.x,&tmp.y);
            if(getDis(tmp,c.co)<=c.r+eps){
                ve.push_back(tmp);
            }
        }
        //cout<<"num "<<ve.size()<<endl;
        //sort(ve.begin(),ve.end(),cmp);
        int vesize = ve.size();
        int ans = 0;
        for(int i = 0;i<ve.size();i++){

            //cout<<"ang0 "<<ang0<<endl;
            int num = 1;
            for(int j = 0;j<ve.size();j++){
               if(i!=j&&xmulti(ve[j],ve[i],c.co)>=0){
                   num++;
               }
            }
            ans = max(ans,num);
        }
        printf("%d\n",ans);
    }
    return 0;
}//
// Created by 王若璇 on 16/8/3.
//
#include <iostream>
#include <algorithm>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const double eps = 1e-6;
const int max_n = 200;
const double pi = acos(-1.0);
struct Point{
    double x,y;
};
struct Circle{
    Point co;
    double r;
};
double getDis(Point p1,Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
double xmulti(Point p1,Point p2,Point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
Circle c;
bool cmp(const Point& p1,const Point& p2){
    double tmp = xmulti(p1,p2,c.co);
    return tmp>0;
}
vector<Point> ve;
int main(){
    int n;
    while(scanf("%lf%lf%lf",&c.co.x,&c.co.y,&c.r)!=EOF){
        ve.clear();
        scanf("%d",&n);
        //cout<<"n "<<n<<endl;
        if(c.r<0){
            break;
        }
        for(int i = 0;i<n;i++){
            Point tmp;
            scanf("%lf%lf",&tmp.x,&tmp.y);
            if(getDis(tmp,c.co)<=c.r+eps){
                ve.push_back(tmp);
            }
        }
        //cout<<"num "<<ve.size()<<endl;
        //sort(ve.begin(),ve.end(),cmp);
        int vesize = ve.size();
        int ans = 0;
        for(int i = 0;i<ve.size();i++){

            //cout<<"ang0 "<<ang0<<endl;
            int num = 1;
            for(int j = 0;j<ve.size();j++){
               if(i!=j&&xmulti(ve[j],ve[i],c.co)>=0){
                   num++;
               }
            }
            ans = max(ans,num);
        }
        printf("%d\n",ans);
    }
    return 0;
}