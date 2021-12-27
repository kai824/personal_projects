// ans.cpp 8 Feb 17, 20:59:19 100 0 Judging completed in 4.322s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int ans=0,h,w;
    string a;
    cin>>h>>w;
    for(int x=0;x<h;x++){
        cin>>a;
        for(int y=0;y<w;y++){
            if(a[y]=='#')ans++;
        }
    }cout<<ans;
    return 0;
}