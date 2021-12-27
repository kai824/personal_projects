// ans.cpp 30 Apr 17, 20:59:43 100 0.01 Judging completed in 4.513s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    for(ll x=a;x<=b;x++){
        if(x%c==0 && x%d==0){
            cout<<"FizzBuzz\n";
        }else if(x%c==0){
            cout<<"Fizz\n";
        }else if(x%d==0){
            cout<<"Buzz\n";
        }else{
            cout<<x<<'\n';
        }
    }
    return 0;
}