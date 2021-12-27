// ans.cpp 25 Jun 18, 08:39:46 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std
int arr[2][15];
bool bit=1,flag=0;
inline char gec()
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
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n=get(),k=get(),a;
    long long ans=0;
    a=get();
    a%=k;
    arr[0][a]=1;
    if(a==0)ans+=1;
    for(int x=1;x<n;x++){
        a=get()%k;
        for(int y=0;y<k;y++){arr[bit][y]=0;}
        arr[bit][a]=1;
        for(int y=0;y<k;y++){
            arr[bit][(y+a)%k]+=arr[!bit][y];
            if((y+a)%k==0)ans+=arr[bit][(y+a)%k];
        }
        bit=!bit;
        if(flag)break;
    }
    cout<<ans;
    return 0;
}