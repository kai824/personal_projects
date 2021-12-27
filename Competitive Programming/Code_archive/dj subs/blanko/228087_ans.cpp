// ans.cpp 22 Oct 17, 15:50:11 52 0.66 Judging completed in 4.773s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,prev=0,y;
    string a;
    bool b=true;
    cin>>n>>k>>a;
    priority_queue< pii ,vector<pii>,greater<pii> > pq;
    vector<pii> v;
    k=n-k;
    for(int x=0;x<n-k;x++){
        pq.push(make_pair(a[x]-'0',x));
    }
    for(int x=n-k;x<n;x++){
        pq.push(make_pair(a[x]-'0',x));
        for(int x=0;x<v.size();x++){
        	pq.push(v.back());
        }
        y=v.size();
        for(int x=0;x<y;x++){
            v.pop_back();
        }
        while(pq.top().second<prev||(pq.top().first==0 && b && (x+1)<n )){
        	if(pq.top().second>prev){
        		v.push_back(pq.top());
        	}
            pq.pop();
        }
        cout<<pq.top().first;
        b=false;
        prev=pq.top().second;
        pq.pop();
    }
    return 0;
}