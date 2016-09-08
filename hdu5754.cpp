#include <bits/stdc++.h>

using namespace std;

int dp[1010][1010];

int main()
{
    memset(dp,-1,sizeof(dp));
    dp[1][1]=0;
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            int a=dp[i][j-1],b=dp[i-1][j],c=dp[i-1][j-1];
            if(a!=0&&b!=0&&c!=0)
            {
                dp[i][j]=0;
                continue;
            }
            if(a!=1&&b!=1&&c!=1)
            {
                dp[i][j]=1;
                continue;
            }
            if(a!=2&&b!=2&&c!=2)
            {
                dp[i][j]=2;
                continue;
            }
            dp[i][j]=3;
        }
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,type;
        scanf("%d%d%d",&type,&n,&m);
        if(type==1)
        {
            if(dp[n][m]) printf("B\n");else printf("G\n");
        }
        if(type==2)
        {
            int x=n-1,y=m-1;
            int z=x^y;
            if(z) printf("B\n");else printf("G\n");
        }
        if(type==3)
        {
            if(n>m) swap(n,m);
            int x=n-1,y=m-1;
            if((x*2<y)||(y*2<x)||(x*2-y)%3!=0||(y*2-x)%3!=0) printf("D\n");
            else
            {
                int z=(x*2-y)/3+(y*2-x)/3;
                if(z&1)
                {
                    if(z+z/2>=n) printf("D\n");else printf("B\n");
                }
                else
                {
                    if(z+z/2>=n) printf("D\n");else printf("G\n");
                }
            }
        }
        if(type==4)
        {
            int a=n-1,b=m-1,t,d;
            if ( a > b ) {
                t = a;
                a = b;
                b = t;
            }
            d = b - a;
            t = floor( d * ( sqrt(5.0) + 1 ) / 2 );
            printf( (t == a) ? "G\n" : "B\n" );
        }
    }
    return 0;
}