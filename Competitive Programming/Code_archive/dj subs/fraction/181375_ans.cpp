// ans.cpp 15 Jan 17, 14:52:43 100 0 Judging completed in 6.574s on AWS Ireland.
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