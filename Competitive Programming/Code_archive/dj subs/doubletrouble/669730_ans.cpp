// ans.cpp 31 Dec 19, 17:41:55 0 1 Judging completed in 5.581s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,a;
    cin>>n>>k;
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int x=0;x<n;x++){
        cin>>a;
        pq.push(a);
    }
    for(int x=0;x<k;x++){
        x=pq.top();
        pq.pop();
        pq.push(x*2);
    }
    for(int x=1;x<n;x++){
        pq.pop();
    }
    cout<<pq.top();
    return 0;
}