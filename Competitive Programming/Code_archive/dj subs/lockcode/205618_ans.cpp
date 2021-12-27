// ans.cpp 1 May 17, 20:22:46 100 0 Judging completed in 6.001s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll a,root;
    for(ll x=0;x<4;x++){
        cin>>a;
        if(a<=1){
            cout<<"Wrong code";
            return 0;
        }
        root=sqrt(a);
        for(ll y=2;y<root+1;y++){
            if(a%y==0){
                cout<<"Wrong code";
                return 0;
            }
        }
    }
    cout<<"Opening...";
    return 0;
}