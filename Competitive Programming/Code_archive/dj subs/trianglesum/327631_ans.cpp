// ans.cpp 19 Feb 18, 11:03:37 100 0.64 Judging completed in 7.381s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll n,k,a,sum,current,maxi=INT_MIN,ps[5005][5005],ts[5005][5005];

bool flag=0;

char gec()
{
    char c=getchar_unlocked();
    if ((c<'0'||c>'9')&&(c!=' '&&c!='\n')) flag=1;
    return c;
}
inline int get()
{
    int ret=0;
    char c=gec();
    while (c<'0'||c>'9')
    {
        if (flag) return 0;
        c=gec();
    }
    while (c>='0'&&c<='9')
    {
        (ret*=10)+=c-'0';
        c=gec();
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    n=get();k=get();
    if(n>5000){
        while(true){}
    }
    for(ll x=1;x<=n;x++){
    	current=0;
        for(ll y=1;y<=n;y++){
            a=get();
            current+=a;
            ps[x][y]=ps[x-1][y]+current;
            ts[x][y]=ts[x-1][y+1]+a;
            if(flag){
            	flag=false;
            	break;
            }
        }
    }
    for(ll x=1;x<=n-k+1;x++){
        sum=0;
        for(ll y=0;y<k;y++){
            sum+=(ts[y+x][1]-ts[x-1][y+2]);
        }
        for(ll y=1;y<=n-k+1;y++){
        	maxi=max(maxi,sum);
        	sum-=ps[x+k-1][y]-ps[x+k-1][y-1]+ps[x-1][y-1]-ps[x-1][y];
        	sum+=ts[x+k-1][y+1]-ts[x-1][y+k+1];
        }
    }
    cout<<maxi;
    return 0;
}