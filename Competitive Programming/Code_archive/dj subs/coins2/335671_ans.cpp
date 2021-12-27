// ans.cpp 11 Mar 18, 16:52:33 0 3.01 Judging completed in 8.835s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#pragma optimise
bool a[30000001],flag=0;

inline char gec()
{
    static char c=getchar_unlocked();
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
    static int n=get(),q=get();
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
        putchar_unlocked('0'+(int)now);
    }
}