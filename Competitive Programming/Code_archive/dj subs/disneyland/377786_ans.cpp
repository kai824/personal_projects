// ans.cpp 16 Jul 18, 00:00:16 10 1 Judging completed in 3.649s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
deque<int>dq;
bool served[1000005];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,a,b,c;
    cin>>n;
    priority_queue<pair<int,int> > pq;
    for(int x=0;x<n;x++){
        cin>>a;
        if(a==0){
			if(dq.size()==0){
				cout<<"-1\n";
			}else{
                cout<<dq.front()<<'\n';
                if(dq.front()>=1000005 || dq.front()<0){
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