// ans.cpp 10 Jun 17, 22:13:18 0 0 Judging completed in 6.262s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n,m;
ll s(int b){//returns sum of 1^2+2^2+3^2...
    b%=m;
    return(((((b*(b+1))%m)*(2*b + 1))/6)%m);
}
ll process(int a){
    if(a%2==1){
        return(process(a-1)%m+(((a*(a+1))/2)%m));
    }
    a/=2;
    return((s(a)*4)%m);
}
int main(){
    cin>>n>>m;
    cout<<process(n)%m;
    return 0;
}