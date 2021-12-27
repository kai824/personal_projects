// ans.cpp 17 Oct 17, 09:54:48 100 0.04 Judging completed in 3.362s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
    return(a.second<b.second);
}
vector<pair<int,int> > events,t;
int getd(int a){//as of this time, how many things did you do?
    int lo,hi,mid;
    lo=0;
    hi=t.size()-1;
    while(lo<hi){//find the largest that is smaller or equal
    	mid=lo+hi;
        mid-=(lo+hi)/2;
        if(t[mid].second<=a)lo=mid;
        else hi=mid-1;//t[mid]>=a
    }
    return t[lo].first;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a>>b;
        events.push_back(make_pair(a,b));
    }
    sort(events.begin(),events.end(),cmp);
    t.push_back(make_pair(0,0));//events completed, time
    for(int x=0;x<n;x++){
t.push_back(make_pair(max(getd(events[x].second),getd(events[x].first)+1),events[x].second));
    }
    cout<<t.back().first;
    return 0;
}