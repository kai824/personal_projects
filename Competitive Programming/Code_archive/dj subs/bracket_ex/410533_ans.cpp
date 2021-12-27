// ans.cpp 12 Nov 18, 13:21:38 0 0 Judging completed in 12.794s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#pragma O3
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    string b,c="",d=" ";
    int a;
    cin>>a>>b;
    vector<char>v;
    v.push_back(b[0]);
    for(int x=1;x<b.length();x++){
        if(v.size()==0){
            v.push_back(b[x]);
            continue;
        }
        if((v.back()=='('&&b[x]==')') || (v.back()=='['&&b[x]==']') || (v.back()=='{'&&b[x]=='}')){
            v.pop_back();
        }else{
            v.push_back(b[x]);
        }
    }
    return 0;
}