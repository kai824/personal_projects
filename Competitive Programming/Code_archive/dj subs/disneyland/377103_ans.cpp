// ans.cpp 12 Jul 18, 12:05:31 0 1.01 Judging completed in 4.21s on AWS Oregon.
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
            cout<<dq.front()<<'\n';
            served[dq.front()]=1;
            dq.pop_front();
        }else{
            cin>>b>>c;
            served[c]=0;
            while(!pq.empty()){
                if(served[pq.top().second])pq.pop();
            }
            if(pq.empty())dq.push_back(c);
            else if(b>pq.top().second)dq.push_front(c);
            else dq.push_back(c);
            pq.push(make_pair(b,c));
        }
    }
    return 0;
}