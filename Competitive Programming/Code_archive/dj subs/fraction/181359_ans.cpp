// ans.cpp 15 Jan 17, 14:28:12 37 0 Judging completed in 5.513s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int process(int a,int b){
    if(b==0)return a;
    else return process(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c;
    cin>>a>>b;
    c=process(min(a,b),max(a,b));
    cout<<a/c<<'/'<<b/c;
    return 0;
}