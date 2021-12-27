// ans.cpp 12 Nov 18, 13:18:17 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#pragma O3
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    string a,c="",d=" ";
    int b;
    cin>>b>>a;
    vector<char>v;
    v.push_back(a[0]);
    for(int x=1;x<a.length();x++){
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