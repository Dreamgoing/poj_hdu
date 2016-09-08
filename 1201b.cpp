//线段树维护祥看

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int max_n = 50000+100;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
struct seg{
    int a,b,c;
    bool operator<(const seg& s) const {
        return b<s.b;
    }
}s[max_n];
int segTree[max_n*4+10];
void pushup(int rt){
    segTree[rt] = segTree[rt<<1]+segTree[rt<<1|1];
}
void update(int p,int l,int r,int rt){
    if(l==r){
        segTree[rt] = 1;
        return;
    }
    int m = (l+r)>>1;
    if(p<=m){
        update(p,lson);
    } else{
        update(p,rson);
    }
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return segTree[rt];
    }
    int m = (l+r)>>1;
    int ret = 0;
    if(L<=m){
        ret+=query(L,R,lson);
    }
    if(R>m){
        ret+=query(L,R,rson);
    }
    return ret;
}
vector<int> p;
bool isexist[max_n];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    p.clear();
    while (cin>>n){
        memset(isexist,0, sizeof(isexist));
        memset(segTree,0, sizeof(segTree));
        int ans = 0;
        for(int i = 0;i<n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;
        }
        sort(s,s+n);
        for(int i = 0;i<n;i++){
            int num = 0;
            num = query(s[i].a,s[i].b,1,50000,1);
            if(num>=s[i].c){
                continue;
            } else{
                int cnt = s[i].c-num;
                int it = 0;
                int pos = 0;
                while (it<cnt){
                    if(!isexist[s[i].b-pos]){
                        update(s[i].b-pos,1,50000,1);
                        isexist[s[i].b-pos] = true;
                        it++;
                        ans++;
                    }
                    pos++;
                }
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}