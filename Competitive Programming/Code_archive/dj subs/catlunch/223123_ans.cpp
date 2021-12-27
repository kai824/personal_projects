// ans.cpp 17 Oct 17, 21:03:36 100 0.16 Judging completed in 8.992s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,a;
    long long maxi=0,current=0;
    cin>>n>>k;
    priority_queue<int> pq;
    deque<int> v;
    for(int x=0;x<k;x++){
        cin>>a;
        pq.push(a);
    }
    for(int x=k;x<n;x++){
        cin>>a;
        v.push_back(a);
    }
    while(!pq.empty()){
        current+=pq.top();
        maxi=max(current,maxi);
        pq.pop();
        if(v.size()>0){
            pq.push(v[0]);
            v.pop_front();
        }
    }
    cout<<maxi;
    return 0;
}