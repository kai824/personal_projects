// ans.cpp 1 Feb 18, 10:19:45 0 1.23 Judging completed in 9.65s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

bool ft[30000001],flag=0;

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

int ls(int x){
    return(x&(-x));
}

void update(int n,int b){
    n++;b++;
    for(;n<30000001;n+=ls(n))ft[n]^=1;;
    for(;b<30000001;b+=ls(b))ft[b]^=1;
}
int query(int n){
    n++;
    int sum=0;
    for(;n;n-=ls(n))sum^=ft[n];
    return sum;
}
int main() {
    int n=get(),q=get();
    while (q--)
    {
        update(get(),get()+1);
        if (flag) break;
    }
    for (int i=0;i<n;i++)
    {
        putchar_unlocked('0'+query(i));
    }
}