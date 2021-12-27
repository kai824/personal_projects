// ans.cpp 26 Nov 16, 15:54:52 0 0.65 Judging completed in 6.058s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> colours){
  for(int a=0;a<colours.size();a++){
    if(colours[a]==0)return false;
  }
  return true;
}
int main(){
    vector<int>areas;
    vector<int>colours;
    vector<vector<int> > connections;
    deque<int> d;//d are the ones you are working with
    int n,e,b,c;
    cin>>n>>e;
    for(int a=0;a<n;a++){
        connections.push_back(areas);
        colours.push_back(0);//0:no colour  1:colour1    2:colour2
    }
    for(int a=0;a<n;a++){
        cin>>b;
        areas.push_back(b);
    }
    for(int a=0;a<e;a++){
        cin>>b>>c;
        connections[b-1].push_back(c);
        connections[c-1].push_back(b);
    }
    b=areas[0];//area of colour 1 islands
    c=0;//area of colour 2 islands
    colours[0]=1;
    d.push_back(1);
    while(d.size()>0){
        n=d.size();
        for(int a=0;a<n;a++){
            for(int e=0;e<connections[d[0]-1].size();e++){
                d.push_back(connections[d[0]-1][e]);
                if(colours[connections[d[0]-1][e]-1]==0) c=c+areas[connections[d[0]-1][e]-1];
                colours[connections[d[0]-1][e]-1]=2;
            }
            d.pop_front();
        }
        if(check(colours)) break;
        n=d.size();
        for(int a=0;a<n;a++){
            for(int e=0;e<connections[d[0]-1].size();e++){
                d.push_back(connections[d[0]-1][e]);
                if(colours[connections[d[0]-1][e]-1]==0) b=b+areas[connections[d[0]-1][e]-1];
                colours[connections[d[0]-1][e]-1]=1;
            }
            d.pop_front();
        }
        if(check(colours)) break;
    }
    cout<<min(b,c);
    return 0;
}