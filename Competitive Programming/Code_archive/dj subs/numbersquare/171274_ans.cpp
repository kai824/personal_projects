// ans.cpp 15 Dec 16, 22:08:31 100 0 Judging completed in 4.297s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int a;
int mmin(int x, int y){
    x=min(x,(2*a+1)-x);
    y=min(y,(2*a+1)-y);
    return(min(x,y));
}
int main() {
    cin>>a;
    for(int x=1;x<=2*a;x++){
        for(int y=1;y<=2*a;y++){
            cout<<mmin(x,y);
        }
        cout<<endl;
    }
    return 0;
}