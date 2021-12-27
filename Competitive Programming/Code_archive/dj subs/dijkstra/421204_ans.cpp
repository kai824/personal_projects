// ans.cpp 24 Nov 18, 23:26:27 100 0.46 Judging completed in 2.724s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,e,start,end,a,b,c;
    cin>>t>>e;
    start=1;end=t;
    priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > w;//what you are working with
    pair<int,int> top;
    int distances[t+5];
    fill_n(distances,t+5,INT_MAX);
    distances[start]=0;
    vector<vector<pair<int,int> > > adjmatrix(t+1);
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        adjmatrix[a].push_back(make_pair(b,c));
        adjmatrix[b].push_back(make_pair(a,c));
    }
    w.push(make_pair(0,start));
    while(!w.empty()){
        top=w.top();
        swap(top.first, top.second);
        w.pop();
        if(distances[top.first]>=top.second){
            distances[top.first]=top.second;
            for(int x=0;x<adjmatrix[top.first].size();x++){
                if(distances[top.first]+adjmatrix[top.first][x].second<distances[adjmatrix[top.first][x].first]){
                    distances[adjmatrix[top.first][x].first]=distances[top.first]+adjmatrix[top.first][x].second;
                    w.push(make_pair(distances[adjmatrix[top.first][x].first],adjmatrix[top.first][x].first));
                }
            }
        }
    }
    cout << distances[end];
    return 0;
}