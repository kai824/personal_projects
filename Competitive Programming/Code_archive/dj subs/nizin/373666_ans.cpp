// ans.cpp 30 Jun 18, 23:01:51 100 0.07 Judging completed in 2.838s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    deque<int> d;
    int n,a,ans=0;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        d.push_back(a);
    }
    while(d.size()>1){
        if(d[0]==d[d.size()-1]){
            d.pop_front();
            d.pop_back();
        }else{
            if(d[0]<d[d.size()-1]){
                d[1]+=d[0];
                d.pop_front();
            }else{
                d[d.size()-2]+=d[d.size()-1];
                d.pop_back();
            }
            ans+=1;
        }
    }
    cout<<ans;
    return 0;
}