// ans.cpp 21 Oct 17, 14:58:58 24 0.76 Judging completed in 5.055s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    //ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,nex=0,prev=-1;//nex refers to the iterator of the next thing we can use...
    string a,ans="";
    priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > pq;
    cin>>n>>k>>a;
    for(int x=0;x<k;x++){
    	pq.push(make_pair(a[x]-'0',x));
    }
    for(int x=k;x<n;x++){
        pq.push(make_pair(a[x]-'0',x));
        while(pq.top().second<prev||(x==k && k+2<n && pq.top().first==0) ){
            pq.pop();
        }
        prev=pq.top().second;
        cout<<pq.top().first;
        pq.pop();
    }
    return 0;
}