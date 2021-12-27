// ans.cpp 12 Nov 18, 21:41:22 67 1 Judging completed in 4.498s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    unsigned long long n,k,cur_end=0,ans=0;
    cin>>n>>k;
    long long arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    deque<pair<long long,long long> > max_dq,min_dq;//value, it
    max_dq.push_back(make_pair(arr[0],0));
    min_dq.push_back(make_pair(arr[0],0));
    for(int x=0;x+1<n;x++){
        while(max_dq[0].second<x){
            max_dq.pop_front();
            if(max_dq.size()==0)while(true){}
        }
        while(min_dq[0].second<x){
            min_dq.pop_front();
            if(min_dq.size()==0)while(true){}
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
        ans+=n-cur_end;
    }
    cout<<ans;
    return 0;
}