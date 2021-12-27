// ans.cpp 14 Feb 18, 08:35:11 0 0 Judging completed in 5.374s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r,c,n,maxh=INT_MIN,ansx,ansy,x1,x2,y1,y2,h1,h2;
    cin>>r>>c>>n;
    if(n==1 && c==1){
        cin>>r>>c>>n;
        cout<<r<<' '<<c<<' '<<n;
    }else if(n==2 && c==1){
        cin>>x1>>y1>>h1>>x2>>y2>>h2;
        if(abs(h2-h1)>=abs(x1-x2)){
            if(h2>h1)cout<<x2<<' '<<y2<<' '<<h2;
            else cout<<x1<<' '<<y1<<' '<<h1;
            return 0;
        }
        if(h1<h2){
            swap(h1,h2);swap(x1,x2);swap(y1,y2);
        }
        if(h2<=h1){
            if(x2>x1){
                x2-=(h2-h1);
            }else{//x2<x1
                x2+=(h2-h1);
            }
            //now at the same height
            cout<<y1<<' '<<(x1+x2)/2<<' ';
            cout<<max(abs(x2-((x1+x2)/2)),abs(x2-((x1+x2)/2)))+h1;
        }
    }
    return 0;
}