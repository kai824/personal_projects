// ans.cpp 3 Feb 20, 13:19:27 100 0.38 Judging completed in 4.609s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll vals[26],cur_val=0,ans=0;
    map<pair<char,ll>,ll> mp;
    for(int x=0;x<26;x++){
        cin>>vals[x];
    }
    string s;
    cin>>s;
    for(int x=0;x<s.length();x++){
        if(mp.find(make_pair(s[x],cur_val))==mp.end()){
            mp[make_pair(s[x],cur_val)]=1;
        }else mp[make_pair(s[x],cur_val)]++;
        cur_val+=vals[s[x]-'a'];
        ans+=mp[make_pair(s[x],cur_val)];
    }
    cout<<ans;
    return 0;
}