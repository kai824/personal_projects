// ans.cpp 26 Jan 19, 20:46:49 0 1 Judging completed in 4.204s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n,a=0,b=0;
    cin>>n;
    for(int x=1;x*x<=n;x++){
        if((n%x)==0){
            a+=x;
            if(x*x!=n)a+=(n/x);
        }
    }
	a-=n;
    for(int x=1;x*x<=a;x++){
        if((a%x)==0){
            b+=x;
            if(x*x!=a)b+=(a/x);
        }
    }
	b-=a;
    if(b==n){
        cout<<a;
    }else cout<<-1;
    return 0;
}