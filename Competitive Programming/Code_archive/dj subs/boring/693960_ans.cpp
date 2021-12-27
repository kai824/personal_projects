// ans.cpp 3 Feb 20, 13:14:04 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll vals[26],cur_val=0,ans=0;
    map<pair<char,ll>,ll> mp;
    for(int x=0;x<26;x++){
        cin>>vals[x];
        mp[make_pair('a'+x)]=1;
    }
    string s;
    cin>>s;
    for(int x=0;x<s.length();x++){
        cur_val+=vals[s[x]-'a'];
        ans+=mp[make_pair(s[x],cur_val)];
        mp[make_pair(s[x],cur_val)]++;
    }
    cout<<ans;
    return 0;
}