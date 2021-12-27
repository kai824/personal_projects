// ans.cpp 15 Jul 18, 23:59:23 10 1 Judging completed in 4.018s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
deque<ll>dq;
bool served[1000005];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,a,b,c;
    cin>>n;
    priority_queue<pair<ll,ll> > pq;
    for(ll x=0;x<n;x++){
        cin>>a;
        if(a==0){
			if(dq.size()==0){
				cout<<"-1\n";
			}else{
                cout<<dq.front()<<'\n';
                if(dq.front()>=1000005){
                    while(true){};
                }
                served[dq.front()]=1;
                if(dq.size()==0)while(true){};
                dq.pop_front();
			}
        }else{
            cin>>b>>c;
            while(!pq.empty()){
                if(pq.empty())break;
                if(served[pq.top().second]==1)pq.pop();
                else break;
            }
            if(pq.empty())dq.push_back(c);
            else if(b>=pq.top().first)dq.push_front(c);
            else dq.push_back(c);
            pq.push(make_pair(b,c));
        }
    }
    return 0;
}