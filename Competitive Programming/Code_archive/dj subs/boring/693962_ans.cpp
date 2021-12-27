// ans.cpp 3 Feb 20, 13:15:34 0 0.22 Judging completed in 4.417s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll vals[26],cur_val=0,ans=0;
    map<pair<char,ll>,ll> mp;
    for(int x=0;x<26;x++){
        cin>>vals[x];
        mp[make_pair('a'+x,0)]=1;
    }
    string s;
    cin>>s;
    for(int x=0;x<s.length();x++){
        cur_val+=vals[s[x]-'a'];
        if(mp.find(make_pair(s[x],cur_val))==mp.end()){
            mp[make_pair(s[x],cur_val)]=1;
            continue;
        }
        ans+=mp[make_pair(s[x],cur_val)];
        mp[make_pair(s[x],cur_val)]++;
    }
    cout<<ans;
    return 0;
}