// ans.cpp 2 Nov 16, 09:39:27 100 0 Judging completed in 7.479s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c,e;
    cin>>a;
    int d[a];
    for(b=0;b<a;b=b+1){
        cin>>c;
        d[b]=c;
    }
    while(1==1){
        e=0;
        for(b=0;b<(a-1);b=b+1){
            if(d[b]>d[(b+1)]){
                c=d[b];
                d[b]=d[b+1];
                d[b+1]=c;
                e=1;
            }
        }
        if(e==0) break;
    }
    for(b=0;b<a;b=b+1){
        cout<<d[b];
        if((a-b)>1) cout<<" ";
    }
    return 0;
}