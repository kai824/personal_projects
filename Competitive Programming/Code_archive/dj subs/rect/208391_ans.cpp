// ans.cpp 30 May 17, 21:40:33 100 0 Judging completed in 9.487s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
struct coords{
    int x,y;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    coords a1,a2;//stores the answer...
    coords i1,i2;//when collecting input...
    cin>>n;
    cin>>a1.x>>a2.x>>a1.y>>a2.y;
    for(int x=1;x<n;x++){
        cin>>i1.x>>i2.x>>i1.y>>i2.y;
        if(i1.x>a2.x || i2.x<a1.x){
            cout<<0;
            return 0;
        }
        if(i1.y>a2.y || i2.y<a1.y){
            cout<<0;
            return 0;
        }
        a1.x=max(a1.x,i1.x);
        a1.y=max(a1.y,i1.y);
        a2.x=min(a2.x,i2.x);
        a2.y=min(a2.y,i2.y);
    }
    cout<<(a2.x-a1.x)*(a2.y-a1.y);
    return 0;
}