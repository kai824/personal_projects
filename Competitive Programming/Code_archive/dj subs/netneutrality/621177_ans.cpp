// ans.cpp 2 Dec 19, 12:20:51 60 0.61 Judging completed in 4.626s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int ps[1000005];
set<pair<int,int> >::iterator it;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n,a,end=0;
    pair<int,int> ans=make_pair(INT_MAX,0);
    //abs difference in sum, number of fish saved...
    set<pair<int,int> > ss;
	ss.insert(make_pair(0,0));
    //prefix sum, iterator...
    cin>>n;
    for(int x=1;x<=n;x++){
        cin>>a;
        ps[x]=ps[x-1]+a;
        if(abs(a)<ans.first){
            ans=make_pair(abs(a),1);
            end=x;
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
        if(it==ss.end() || it->first!=ps[x])ss.insert(make_pair(ps[x],x));
    }
    cout<<end-ans.second<<' '<<end-1;
    return 0;
}