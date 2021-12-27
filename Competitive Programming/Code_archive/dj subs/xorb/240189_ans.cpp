// ans.cpp 4 Nov 17, 10:21:55 100 0 Judging completed in 6.675s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    deque<int> x2,y2;
    int x,y,b,ans=0,a;
    cin>>x>>y>>b;
    while(x>0){
        x2.push_front(x%b);
        x/=b;
    }
    while(y>0){
        y2.push_front(y%b);
        y/=b;
    }
    while(x2.size()<y2.size()){
        x2.push_front(0);
    }
    while(y2.size()<x2.size()){
        y2.push_front(0);
    }
    for(int it=0;it<x2.size();it++){
        ans*=b;
        ans+=(x2[it]+y2[it])%b;
    }
    cout<<ans;
    return 0;
}