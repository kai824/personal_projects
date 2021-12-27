// ans.cpp 1 May 17, 20:22:00 80 0 Judging completed in 6.292s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a,root;
    for(ll x=0;x<4;x++){
        cin>>a;
        if(a<=1){
            cout<<"Wrong code";
            return 0;
        }
        root=sqrt(a);
        for(ll y=2;y<root;y++){
            if(a%y==0){
                cout<<"Wrong code";
                return 0;
            }
        }
    }
    cout<<"Opening...";
    return 0;
}