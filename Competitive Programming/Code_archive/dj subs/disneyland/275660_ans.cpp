// ans.cpp 2 Dec 17, 14:39:44 0 0.28 Judging completed in 4.147s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b,c;
    cin>>n;
    map<int,bool>mp;
    deque<pair<int,int> > q;//priority,id
    priority_queue<pair<int,int> > pq;
    for(int x=0;x<n;x++){
        cin>>a;
        if(a==0){
            if(q.size()==0){
                cout<<"-1\n";
                continue;
            }
            cout<<q.front().second<<'\n';;
            mp[q.front().second]=false;
            q.pop_front();
        }else{
            cin>>b>>c;//priority,id
            
            if(pq.empty()){
                q.push_back(make_pair(b,c));
                mp[c]=true;
                continue;
            }
            
            while(mp[pq.top().second]!=true){
                pq.pop();
            }
            if(b>pq.top().first){
                q.push_front(make_pair(b,c));
            }else{
                q.push_back(make_pair(b,c));
            }
            mp[c]=true;
        }
    }
    return 0;
}