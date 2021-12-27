// ans.cpp 26 Dec 16, 22:54:27 25 0 Judging completed in 5.223s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return(a>b);
}
int main() {
    int n,v,b,c=0,ans=0;
    vector<int> coins;
    cin>>n>>v;
    for(int a=0;a<n;a++){
        cin>>b;
        if(b<=v)coins.push_back(b);
    }
    sort(coins.begin(),coins.end(),cmp);
    for(int a=0;(a<coins.size());a++){
        ans+=v/coins[a];
        v=v%coins[a];
        if(v==0){
            cout<<ans;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}