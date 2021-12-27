// ans.cpp 14 Dec 19, 15:07:18 100 0 Judging completed in 3.737s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<pair<int,int> > data;
    vector<pair<int,int> > change;
    pair<int,int> t;
    change.push_back(t);//it will just be there to fill the space
    int a,b,c;
    cin>>a;
    cin>>b>>c;
    t.first=b;
    t.second=c;
    data.push_back(t);
    for(int d=0;d<a;d++){
        cin>>b;
        t.first=b;
        data.push_back(t);
    }
    for(int d=1;d<=a;d++){
        cin>>b;
        data[d].second=b;
    }
    for(int d=1;d<a;d++){
        cin>>b;
        t.first=b;
        change.push_back(t);
    }
    for(int d=1;d<a;d++){
        cin>>b;
        change[d].second=b;
    }
    cin>>b>>c;
    t.first=b;
    t.second=c;
    data.push_back(t);
    data[a].first += data[a+1].first;
    data[a].second += data[a+1].second;
    for(int d=a-1;d>0;d=d-1){
        data[d].first=data[d].first+min(data[d+1].first,(data[d+1].second+change[d].first));
/*-----------------------------------------------------------------------------*/
        data[d].second=data[d].second+min(data[d+1].second,(data[d+1].first+change[d].second));
    }
    data[0].first += data[1].first;
    data[0].second += data[1].second;
    cout<<min(data[0].first,data[0].second);
    return 0;
}