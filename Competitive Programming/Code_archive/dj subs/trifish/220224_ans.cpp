// ans.cpp 10 Sep 17, 22:43:43 0 0 Judging completed in 6.23s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n,m;
ll p1(){//sum of first n integers
    return (((n*(n+1))/2)%m)%m;
}
ll p2(){//sum of square of first n integers
    bool b;
    if(n%2==0)b=true;
    else b=false;
    n/=2;
    ll ans=(((((n%m)*((n+1)%m))%m)*(((2*n)+1)%m))/6)%m;
    n*=2;
    ans*=n;
    ans%=m;
    if(!b){
    	n+=1;
        ans+=((n*(n-1))%m);
        ans%=m;
    }
    return ans;
}
ll p3(){
    return(((p1()*n)%m-p2())%m);
}
int main(){
    cin>>n>>m;
    cout<<p3();
    //cout<<p1()<<' '<<p2();
    return 0;
}