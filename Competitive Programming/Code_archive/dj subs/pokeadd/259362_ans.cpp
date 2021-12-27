// ans.cpp 17 Nov 17, 15:27:22 60 0 Judging completed in 2.708s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c,d;
    string ans="";
    cin>>a>>b>>c;
    if(c==0){
        while(true){}
    }
    vector<ll> v;
    while(a>0&&b>0){
        d=a%c;
        d+=b%c;
        d%=c;
        v.push_back(d);
        a/=c;
        b/=c;
    }
    bool started=false;
    while(v.size()>0){
        if(v.back()==0){
        	if(started){
        		cout<<v.back();
        	}
        }else{
        	cout<<v.back();
        	started=true;
        }
        v.pop_back();
    }
    if(started==false){
    	cout<<"0";
    }
    return 0;
}