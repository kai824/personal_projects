// ans.cpp 18 Jan 18, 09:06:45 100 1.05 Judging completed in 12.103s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

bool a[30000001],flag=0;

char gec()
{
    char c=getchar();
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
    int n=get(),q=get();
    while (q--)
    {
        a[get()]^=1;
        a[get()+1]^=1;
        if (flag) break;
    }
    bool now=0;
    for (int i=0;i<n;i++)
    {
        now^=a[i];
        putchar('0'+(int)now);
    }
}