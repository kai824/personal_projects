// ans.cpp 14 Feb 18, 08:34:28 0 0 Judging completed in 6.73s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r,c,n,x1,x2,y1,y2,h1,h2,a;
    cin>>r>>c>>n;
    if(n==1){
        cin>>r>>c>>n;
        cout<<r<<' '<<c<<' '<<n;
    }else if(n==2 && c==1){
        cin>>x1>>y1>>h1>>x2>>y2>>h2;
        if(x1>x2){//ensuring x1<=x2
            swap(h1,h2);swap(y1,y2);swap(x1,x2);
        }
        if(h1<h2){
            x1+=abs(h2-h1);
            h1=h2;
        }else{
            x2-=abs(h1-h2);
            h2=h1;
        }
        //now the heights are the same at max(h1,h2)...
        a=(x1+x2)/2;
        cout<<y1<<' '<<a<<' '<<max(a-x1,x2-a)+h1;
    }
    return 0;
}