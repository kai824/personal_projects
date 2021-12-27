// ans.cpp 10 Dec 16, 15:55:00 45 0.48 Judging completed in 4.697s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b;
    vector<int>hws;
    cin>>a;
    for(int x=0;x<a;x++){
        cin>>b;
        hws.push_back(b);
    }
    sort(hws.begin(),hws.end());
    for(int x=0;x<hws.size();x++){
        cout<<hws[x];
        if(x+1!=hws.size())cout<<' ';
    }
    return 0;
}