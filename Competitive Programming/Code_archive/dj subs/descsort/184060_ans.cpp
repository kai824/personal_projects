// ans.cpp 22 Jan 17, 19:18:19 0 0 Judging completed in 4.248s on AWS Ireland.
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
        cout<<c[x];
        if(x!=a)cout<<' ';
    }
    return 0;
}