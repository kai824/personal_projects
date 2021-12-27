// ans.cpp 12 Jul 18, 12:17:20 10 0 Judging completed in 3.728s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool served[1000005];
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,a,b,c;
    cin>>n;
    deque<ll> dq;
    priority_queue<pair<ll,ll> > pq;
    for(ll x=0;x<n;x++){
        cin>>a;
        if(a==0){
			if(dq.size()==0){
				cout<<"-1\n";
				continue;
			}
            cout<<dq.front()<<'\n';
            served[dq.front()]=1;
            dq.pop_front();
        }else{
            cin>>b>>c;
            served[c]=0;
            while(!pq.empty()){
                if(served[pq.top().second])pq.pop();
                else break;
            }
            if(pq.empty())dq.push_back(c);
            else if(b>pq.top().first)dq.push_front(c);
            else dq.push_back(c);
            pq.push(make_pair(b,c));
        }
    }
    return 0;
}