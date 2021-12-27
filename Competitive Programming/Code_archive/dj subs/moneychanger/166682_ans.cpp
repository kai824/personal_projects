// ans.cpp 2 Dec 16, 17:51:01 15 1 Judging completed in 7.696s on AWS Ireland.
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
        coins.push_back(b);
    }
    sort(coins.begin(),coins.end(),cmp);
    b=0;//b is now used as current value
    while(b!=v){
        if(b+coins[c]<=v){
            ans+=1;
            b+=coins[c];
        }else{
            c++;
        }
    }
    cout<<ans;
    return 0;
}