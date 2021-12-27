// ans.cpp 28 Oct 17, 14:56:02 35 6.02 Judging completed in 10.457s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct stuff{
    ll a1,a2,a3,a;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,q,t,ans;
    cin>>n;
    vector<stuff> v;
    stuff to_add;
    for(ll x=0;x<n;x++){
        cin>>t;
        to_add.a=t;
        to_add.a1=t%13371337;
        to_add.a2=0;
        to_add.a3=0;
        while(t>0){
            to_add.a2+=t%10;
            to_add.a3*=10;
            to_add.a3+=t%10;
            t/=10;
        }
        v.push_back(to_add);
    }
    cin>>q;
    for(ll x=0;x<q;x++){
        cin>>t;
        ans=0;
        for(ll x=1;x<v.size();x++){
            if(t==1){
                if(v[x].a1>v[ans].a1){
                    ans=x;
                }else if(v[x].a1==v[ans].a1 && v[x].a>v[ans].a){
                    ans=x;
                }
            }else if(t==2){
                if(v[x].a2>v[ans].a2){
                    ans=x;
                }else if(v[x].a2==v[ans].a2 && v[x].a>v[ans].a){
                    ans=x;
                }
            }else if(t==3){
                if(v[x].a3>v[ans].a3){
                    ans=x;
                }else if(v[x].a3==v[ans].a3 && v[x].a>v[ans].a){
                    ans=x;
                }
            }
        }
        cout<<v[ans].a<<'\n';
        if(ans!=v.size()-1)swap(v[ans],v.back());
        v.pop_back();
    }
    return 0;
}