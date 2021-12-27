// ans.cpp 19 Oct 17, 13:35:57 100 1.73 Judging completed in 5.81s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,s,r;
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int>b){
    return(a.first.second<b.first.second);
}
vector<pair<int,int> > t;//iterator, distance travelled...
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
    return t[lo].first+((a-t[lo].second)*r);
}

int main(){
    cin>>n>>s>>r;
    pair<pair<int,int>,int> bs[s];//buses...
    for(int x=0;x<s;x++){
        cin>>bs[x].first.first>>bs[x].first.second>>bs[x].second;
    }
    sort(bs,bs+s,cmp);
    t.push_back(make_pair(0,0));
    for(int x=0;x<s;x++){
        t.push_back(make_pair( min(getd(bs[x].first.second),getd(bs[x].first.first)+bs[x].second) ,bs[x].first.second));
    }
    cout<<getd(n);
    return 0;
}