// ans.cpp 25 Aug 17, 21:41:42 100 0.23 Judging completed in 6.296s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main(){
    string a;
    int n,c,b;
    map<string,int> mp;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a>>b;
        mp[a]=b;
    }
    cin>>c;
    b=0;
    for(int x=0;x<c;x++){
        cin>>a;
        b+=mp[a];
    }
    cout<<b/c;
    return 0;
}