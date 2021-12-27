// ans.cpp 26 Jan 19, 20:50:56 0 0.02 Judging completed in 2.004s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n,a=0,b=0;
    cin>>n;
    if(n==0){
        cout<<-1;
        return 0;
    }
    for(long long x=1;x*x<=n;x++){
        if((n%x)==0){
            a+=x;
            if(x*x!=n)a+=(n/x);
        }
    }
	a-=n;
    for(long long x=1;x*x<=a;x++){
        if((a%x)==0){
            b+=x;
            if(x*x!=a)b+=(a/x);
        }
    }
	b-=a;
	if(a<=0){
	    cout<<"-1";return 0;
	}
    if(b==n){
        cout<<a;
    }else cout<<-1;
    return 0;
}