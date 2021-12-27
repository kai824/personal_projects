// ans.cpp 15 Apr 20, 08:36:45 100 0.02 Judging completed in 3.394s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    vector<char> v;
    string a,b;
    bool broke;
    cin>>a>>b;
    for(int x=0;x<a.length();x++){
        v.push_back(a[x]);
        if(v.size()<b.length())continue;
        broke=false;
        for(int i=0;i<b.length();i++){
            if(v[v.size()-i-1]!=b[b.length()-i-1]){
                broke=true;
                break;
            }
        }
        if(broke)continue;
        for(int i=0;i<b.length();i++)v.pop_back();
    }
    if(v.size()==0)cout<<"FRULA\n";
    for(int x=0;x<v.size();x++){
        cout<<v[x];
    }
    return 0;
}