// ans.cpp 15 Jul 18, 23:56:07 10 0 Judging completed in 2.791s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool served[1000005];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,a,b,c;
    cin>>n;
    deque<int> dq;
    priority_queue<pair<int,int> > pq;
    for(int x=0;x<n;x++){
        cin>>a;
        if(a==0){
			if(dq.size()==0){
				cout<<"-1\n";
			}else{
                cout<<dq.front()<<'\n';
                served[dq.front()]=1;
                dq.pop_front();
			}
        }else{
            cin>>b>>c;
            while(!pq.empty()){
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