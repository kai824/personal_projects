// ans.cpp 11 Mar 18, 16:54:38 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#pragma optimise
bool a[30000001],flag=0;
char ccc;
inline void gec()
{
    ccc=getchar_unlocked();
    if ((ccc<'0'||ccc>'9')&&(ccc!=' '&&ccc!='\n')) flag=1;
    //return c;
}
inline int get()
{
    int ret=0;
    ccc=gec();
    while (ccc<'0'||ccc>'9')
    {
        if (flag) return 0;
        gec();
    }
    while (ccc>='0'&&ccc<='9')
    {
        (ret*=10)+=ccc-'0';
        gec();
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