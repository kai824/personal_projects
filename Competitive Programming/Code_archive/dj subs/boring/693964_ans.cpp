// ans.cpp 3 Feb 20, 13:20:05 100 0.35 Judging completed in 5.395s on AWS Oregon.
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
        mp[make_pair(s[x],cur_val)]++;
        cur_val+=vals[s[x]-'a'];
        ans+=mp[make_pair(s[x],cur_val)];
    }
    cout<<ans;
    return 0;
}