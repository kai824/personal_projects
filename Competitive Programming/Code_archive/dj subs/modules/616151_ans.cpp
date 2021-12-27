// ans.cpp 25 Nov 19, 19:00:42 100 2.4 Judging completed in 8.613s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b){
    return(a.first.second<b.first.second);
}

pair<pair<int,int>,int> mods[1000005];
int n,k,it;
bool ok(int a){//checks if satisfaction of a can be achieved
    vector<pair<int,int> > v;//end time, current credit...
    int lo,hi,mid;
    v.push_back(make_pair(0,0));
    for(int x=0;x<n;x++){
        it=mods[x].first.first-a;
        if(it<0){
            if(mods[x].second>v.back().second)v.push_back(make_pair(mods[x].first.second,mods[x].second));
            continue;
        }
        lo=0;hi=v.size()-1;
        while(lo<hi){
            mid=hi-(hi-lo)/2;
            if(v[mid].first<=it){
                lo=mid;
            }else hi=mid-1;
        }
        if(mods[x].second+v[lo].second>v.back().second)v.push_back(make_pair(mods[x].first.second,mods[x].second+v[lo].second));
        if(mods[x].second+v[lo].second>=k){
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int lo,hi,mid,maxi=INT_MIN;
    cin>>n>>k;
    for(int x=0;x<n;x++){
        cin>>mods[x].first.first>>mods[x].first.second>>mods[x].second;
        maxi=max(maxi,mods[x].second);
    }
    if(maxi>=k){
        cout<<1000000000;return 0;
    }
    sort(mods,mods+n,cmp);
    if(ok(0)==false){
        cout<<"-1";return 0;
    }
    lo=0;hi=1e9;
    while(lo<hi){
        mid=hi-(hi-lo)/2;
        if(ok(mid)){
            lo=mid;
        }else{
            hi=mid-1;
        }
    }
    cout<<lo;
    return 0;
}
/*
6 2
0 3 1
1 2 1
2 5 1
3 4 1
4 6 1
3 7 1
45 032 164 383 792
*/