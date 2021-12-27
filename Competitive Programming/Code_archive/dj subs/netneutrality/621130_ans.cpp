// ans.cpp 2 Dec 19, 12:17:13 30 0.48 Judging completed in 4.504s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
long long ps[1000005];
set<pair<long long,int> >::iterator it;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n,a,end=0;
    pair<int,int> ans=make_pair(INT_MAX,0);
    //abs difference in sum, number of fish saved...
    set<pair<long long,int> > ss;
	ss.insert(make_pair(0,0));
    //prefix sum, iterator...
    cin>>n;
    for(int x=1;x<=n;x++){
        cin>>a;
        ps[x]=ps[x-1]+a;
        if(abs(a)<ans.first){
            ans=make_pair(abs(a),1);
        }
        it=ss.upper_bound(make_pair(ps[x],INT_MAX));
        if(it!=ss.end()){
            if(abs(it->first-ps[x])<ans.first){
                ans=make_pair(abs(it->first-ps[x]),x-it->second);
                end=x;
            }else if(abs(it->first-ps[x])==ans.first && x-it->second>ans.second){
                ans.second=x-it->second;
                end=x;
            }
        }
        if(it!=ss.begin()){
            it--;
            if(abs(it->first-ps[x])<ans.first){
                ans=make_pair(abs(it->first-ps[x]),x-it->second);end=x;
            }else if(abs(it->first-ps[x])==ans.first && x-it->second>ans.second){
                ans.second=x-it->second;end=x;
            }
        }
        if(it->first!=ps[x])ss.insert(make_pair(ps[x],x));
    }
    cout<<end-ans.second<<' '<<end-1;
    return 0;
}