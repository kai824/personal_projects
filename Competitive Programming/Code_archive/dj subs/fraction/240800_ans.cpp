// ans.cpp 4 Nov 17, 13:02:56 100 0 Judging completed in 5.571s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
unsigned long long int process(uint64_t a,uint64_t b){
    if(b==0)return a;
    else return process(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unsigned long long int a,b,c;
    cin>>a>>b;
    c=process(min(a,b),max(a,b));
    cout<<a/c<<'/'<<b/c;
    return 0;
}