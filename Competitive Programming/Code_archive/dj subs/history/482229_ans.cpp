// ans.cpp 26 Jan 19, 17:45:57 10 0 Judging completed in 2.835s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,a,prev,longest,cur;
    cin>>n>>m;
    map<int,int> mp;//map item to the "time"
    for(int x=0;x<n;x++){
        cin>>a;
        mp[a]=x+1;
    }
    for(int x=0;x<m;x++){
        longest=0;cur=0;prev=-1;
        for(int y=0;y<n;y++){
            cin>>a;
            a=mp[a];//find the time...
            if(prev<a){
                prev=a;
                cur++;
                longest=max(longest,cur);
            }else{
                prev=-1;
                cur=0;
            }
        }
        cout<<longest<<'\n';
    }
    return 0;
}