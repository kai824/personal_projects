// ans.cpp 12 Jul 18, 12:04:01 0 0 Compilation failed on AWS Oregon.
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
                if(served[pq.top()])pq.pop();
            }
            if(pq.empty())dq.push_back(make_pair(b,c));
            else if(b>pq.top())dq.push_front(make_pair(b,c));
            else dq.push_back(make_pair(b,c));
            pq.push(make_pair(b,c));
        }
    }
    return 0;
}