// ans.cpp 20 Aug 17, 17:30:14 0 0 Judging completed in 7.844s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    map<string, pair<int,pair<int,int> > > mp;
    int a,ans;
    string b;
    short int c,d;
    cin>>a;
    for(int x=0;x<a;x++){
        cin>>b>>c;
        if(c==1){
            cin>>d;
            if(mp[b].second.first==d)mp[b].second.second++;
            else{
            	mp[b].second.second=1;
            }
            mp[b].second.first=d;
            mp[b].first=max(mp[b].first,mp[b].second.second);
        }else{
            cout<<mp[b].first<<'\n';
        }
    }
    return 0;
}