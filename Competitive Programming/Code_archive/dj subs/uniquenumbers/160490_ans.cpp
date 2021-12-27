// ans.cpp 8 Nov 16, 18:24:59 100 0.4 Judging completed in 5.5s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,u=0;
    cin>>a;
    vector<int> d;
    for(int c=0;c<a;c=c+1){
        cin>>b;
        d.push_back(b);
    }
    sort(d.begin(),d.end());
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