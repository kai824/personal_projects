// ans.cpp 22 Jan 17, 19:18:55 100 0 Judging completed in 3.993s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return(a>=b);
}
int main() {
    int a,c[1005];
    cin>>a;
    for(int x=0;x<a;x++){
        cin>>c[x];
    }
    sort(c,c+a,cmp);
    for(int x=1;x<=a;x++){
        cout<<c[x-1];
        if(x!=a)cout<<' ';
    }
    return 0;
}