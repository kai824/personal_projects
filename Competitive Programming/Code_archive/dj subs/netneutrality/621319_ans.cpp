// ans.cpp 2 Dec 19, 12:30:56 0 0.16 Judging completed in 4.41s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
pair<long long,int> ps[1000005];
//the sum...
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n,a,end=0,prev_it=0;
    pair<int,int> ans=make_pair(INT_MAX,0);
    //abs difference in sum, number of fish saved...
    cin>>n;
    ps[0]=make_pair(0,0);
    for(int x=1;x<=n;x++){
        cin>>a;
        ps[x].first=ps[x-1].first+a;
        ps[x].second=x;
    }
    sort(ps,ps+n+1);
    for(int x=1;x<=n;x++){
        if(ps[x].first-ps[prev_it].first<ans.first){
            ans.first=ps[x].first-ps[prev_it].first;
            ans.second=abs(ps[x].second-ps[prev_it].second);
            end=ps[x].second;
        }else if(ps[x].first-ps[prev_it].first==ans.first && abs(ps[x].second-ps[prev_it].second)<ans.second){
            end=ps[x].second;
            ans.second=abs(ps[x].second-ps[prev_it].second);
        }
        if(ps[x].first>ps[prev_it].first){
            prev_it=x;
        }
    }
    cout<<end-ans.second<<' '<<end-1;
    return 0;
}