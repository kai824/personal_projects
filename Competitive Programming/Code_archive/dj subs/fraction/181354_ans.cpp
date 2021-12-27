// ans.cpp 15 Jan 17, 14:22:50 37 1 Judging completed in 6.464s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
long long int process(int a,int b){
    if(b>a)swap(a,b);
    if(b==0)return a;
    else return process(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int a,b,c;
    cin>>a>>b;
    c=process(a,b);
    cout<<a/c<<'/'<<b/c;
    return 0;
}