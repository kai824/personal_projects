// ans.cpp 12 Nov 18, 21:47:30 71 0.86 Judging completed in 8.815s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#pragma O3
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    unsigned long long n,k,cur_end=0,ans=0;
    cin>>n>>k;
    long long arr[n+5];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    deque<pair<long long,long long> > max_dq,min_dq;//value, it
    max_dq.push_back(make_pair(arr[0],0));
    min_dq.push_back(make_pair(arr[0],0));
    for(int x=0;x<n;x++){
        while(max_dq.size()>0 && max_dq[0].second<x){
            max_dq.pop_front();
        }
        while(min_dq.size()>0 && min_dq[0].second<x){
            min_dq.pop_front();
        }
        while(max_dq.size()==0 || min_dq.size()==0 || max_dq[0].first-min_dq[0].first<k){
            cur_end++;
            if(cur_end>=n){
                cur_end=n;
                break;
            }
            while(max_dq.size()>0 && max_dq.back().first<=arr[cur_end]){
                max_dq.pop_back();
            }
            max_dq.push_back(make_pair(arr[cur_end],cur_end));
            
            while(min_dq.size()>0 && min_dq.back().first>=arr[cur_end]){
                min_dq.pop_back();
            }
            min_dq.push_back(make_pair(arr[cur_end],cur_end));
        }
        if(cur_end==n)break;
        ans+=n-cur_end;
    }
    cout<<ans;
    return 0;
}