// ans.cpp 17 Dec 19, 11:35:44 100 0.51 Judging completed in 4.323s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k,a;
    long long ans=0;
    cin>>n>>k;
    pair<int,int> arr[n];
    map<int,int> mp;//weights, count
    map<int,int>::iterator it;
    for(int x=0;x<n;x++){
        cin>>arr[x].second>>arr[x].first;//mass, value...
    }
    sort(arr,arr+n,greater<pair<int,int> >());
    for(int x=0;x<k;x++){
        cin>>a;
        if(mp.find(a)==mp.end()){
            mp[a]=1;
        }else{
            mp[a]++;
        }
    }
    for(int x=0;x<n;x++){
        if(mp.begin()==mp.end())break;
        it=mp.lower_bound(arr[x].second);//the maxx
        if(it==mp.end())continue;
        //find smallest bag that can fit it...
        if(it->second==1)mp.erase(it);
        else it->second--;
        ans+=arr[x].first;
    }
    cout<<ans;
    return 0;
}