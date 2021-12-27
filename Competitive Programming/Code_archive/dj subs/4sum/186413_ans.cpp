// ans.cpp 1 Feb 17, 20:04:53 80 1 Judging completed in 4.093s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c,d,e,f,g;//e is the max, f is the min.
    cin>>a>>b>>c>>d;
    int a2[a+2],b2[b+2],c2[c+2],d2[d+2];// the first additional 2 is for the min, then the max
    e=INT_MIN;
    f=INT_MAX;
    for(int x=2;x<a+2;x++){
        cin>>a2[x];
        e=max(e,a2[x]);
        f=min(f,a2[x]);
    }
    a2[0]=f;
    a2[1]=e;
    e=INT_MIN;
    f=INT_MAX;
    for(int x=2;x<b+2;x++){
        cin>>b2[x];
        e=max(e,b2[x]);
        f=min(f,b2[x]);
    }
    b2[0]=f;
    b2[1]=e;
    e=INT_MIN;
    f=INT_MAX;
    for(int x=2;x<c+2;x++){
        cin>>c2[x];
        e=max(e,c2[x]);
        f=min(f,c2[x]);
    }
    c2[0]=f;
    c2[1]=e;
    e=INT_MIN;
    f=INT_MAX;
    for(int x=2;x<d+2;x++){
        cin>>d2[x];
        e=max(e,d2[x]);
        f=min(f,d2[x]);
    }
    d2[0]=f;
    d2[1]=e;
    //we can now reuse  e and f.
    for(int x=0;x<a;x++){
        f=a2[x+2];
        e=f;
        if(e+b2[0]+c2[0]+d2[0]>0 || e+b2[1]+c2[1]+d2[1]<0){
            continue;
        }
        for(int y=0;y<b;y++){
            e=b2[y+2]+f;
            if(e+c2[0]+d2[0]>0 || e+c2[1]+d2[1]<0){
                continue;
            }
            for(int z=0;z<c;z++){
                g=c2[z+2]+e;
                if(g+d2[0]>0 || g+d2[1]<0){
                    continue;
                }
                for(int xy=0;xy<d;xy++){
                    if(g+d2[xy+2]==0){
                        cout<<a2[x+2]<<' '<<b2[y+2]<<' '<<c2[z+2]<<' '<<d2[xy+2];
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}