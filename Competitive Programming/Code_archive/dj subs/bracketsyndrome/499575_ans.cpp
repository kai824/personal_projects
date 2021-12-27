// ans.cpp 27 Feb 19, 22:37:19 100 0.02 Judging completed in 6.183s on AWS Oregon.
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
            }else{
				v.push_back(a[x]);
			}
            if(v.size()==0)ans++;
        }
    }
    cout<<ans;
    return 0;
}