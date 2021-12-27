// ans.cpp 16 Jul 18, 00:11:06 100 0.38 Judging completed in 3.587s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
deque<int>dq;
//bool served[1000005];
map<int, bool> served;
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
                    //while(true){};
                }
                served[dq.front()]=1;
                if(dq.size()==0);//while(true){};
                dq.pop_front();
			}
        }else{
            cin>>b>>c;
            //if(c>1000000)while(true){};
            while(!pq.empty()){
                if(pq.empty())break;
//                if(pq.top().second>=1000005 || pq.top().second<0)break;
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