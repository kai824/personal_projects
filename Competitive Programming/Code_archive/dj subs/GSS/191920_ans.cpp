// ans.cpp 15 Feb 17, 21:02:00 100 0 Judging completed in 4.394s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return(a>b);
}
int main() {
    int a,ans=0;
    cin>>a;
    int b[a];
    for(int x=0;x<a;x++){
        cin>>b[x];
        ans+=b[x];
    }sort(b,b+a,cmp);
    for(int x=3;x<a;x+=4){
        ans-=b[x];
    }
    cout<<ans;
    return 0;
}