// ans.cpp 2 Dec 19, 14:08:59 100 0.32 Judging completed in 4.35s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a;
    cin>>n;
    vector<int> stuff;
    for(int x=0;x<n;x++){
        cin>>a;
        while(stuff.size()>0 && stuff.back()<=a){
            stuff.pop_back();
        }
        stuff.push_back(a);
    }
    for(int x=stuff.size();x>0;x--){
        cout<<stuff[x-1]<<'\n';
    }
    return 0;
}