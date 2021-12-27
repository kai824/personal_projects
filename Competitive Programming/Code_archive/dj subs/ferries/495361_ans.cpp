// ans.cpp 23 Feb 19, 10:09:03 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int ferries(int N, int M, int * A, int * B, int * C){
    int t=N,e=M,start,end,a,b,c;
    start=1;end=t;
    priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > w;//what you are working with
    pair<int,int> top;
    int distances[t+5];
    fill_n(distances,t+5,INT_MAX);
    distances[start]=0;
    vector<vector<pair<int,int> > > adjmatrix(t+1);
    for(int x=0;x<e;x++){
        a=A[x];b=B[x];c=C[x];
        adjmatrix[a].push_back(make_pair(b,c));
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
    return distances[end];
}