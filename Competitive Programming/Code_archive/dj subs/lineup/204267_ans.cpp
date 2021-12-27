// ans.cpp 16 Apr 17, 14:24:55 100 0.42 Judging completed in 5.055s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,p1=0,p2=0,ans=INT_MAX;
    bool b;
    cin>>n;
    pair<int,int> v[n];
    vector<int> breeds;
    for(int x=0;x<n;x++){
        cin>>v[x].first>>v[x].second;
        b=true;
        for(int y=0;y<breeds.size();y++){
            if(breeds[y]==v[x].second){
                b=false;
                break;
            }
        }
        if(b){
            breeds.push_back(v[x].second);
        }
    }
    sort(v,v+n);
    sort(breeds.begin(),breeds.end());
    map<int,int> itmap;//members of parliament...
    for(int x=0;x<breeds.size();x++){
        itmap[breeds[x]]=x;
    }
    for(int x=0;x<n;x++){
        v[x].second=itmap[v[x].second];
    }
    vector<int> arr;
    for(int x=0;x<breeds.size();x++){
    	arr.push_back(0);
    }
    arr[v[0].second]=1;
    while(p1<n && p2<n){
        b=true;//b is now used as notbroke...
        for(int x=0;x<breeds.size();x++){
            if(arr[x]==0){
                b=false;
                break;
            }
        }
        if(b){
            ans=min(ans,v[p2].first-v[p1].first);
            arr[v[p1].second]--;
            p1++;
        }else{
            p2++;
            if(p2<n)arr[v[p2].second]++;
        }
    }
    cout<<ans;
    return 0;
}