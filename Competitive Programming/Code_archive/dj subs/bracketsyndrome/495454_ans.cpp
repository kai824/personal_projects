// ans.cpp 23 Feb 19, 13:33:18 0 0.02 Judging completed in 3.667s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    string a;cin>>a>>a;
    int ans=0;
    vector<char>v;
    for(int x=0;x<a.length();x++){
        if(a[x]=='('){
            v.push_back(a[x]);
        }else if(a[x]==')'){
            if(v.size()>0 && v.back()=='('){
                v.pop_back();
            }
            if(v.size()==0)ans++;
        }
    }
    cout<<ans;
    return 0;
}