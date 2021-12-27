// ans.cpp 12 Nov 18, 13:08:51 100 1.61 Judging completed in 13.114s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,u=0;
    cin>>a;
    string b;
    vector<string> d;
    for(int c=0;c<a;c=c+1){
        cin>>b;
        d.push_back(b);
    }
    sort(d.begin(),d.end());
    b="";
    for(int c=0;c<d.size();c=c+1){
        if (c!=0){
            if(d[c]==b){
            }
            else u=u+1;
        }
        b=d[c];
    }
    u=u+1;
    cout<<u;
    return 0;
}