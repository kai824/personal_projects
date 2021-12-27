// ans.cpp 20 Aug 17, 17:12:35 0 1.23 Judging completed in 5.82s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
struct ds{
    int arr[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    map<string, ds> mp;
    int a,ans;
    string b;
    int c,d;
    cin>>a;
    for(int x=0;x<a;x++){
        cin>>b>>c;
        if(c==1){
            cin>>d;
            mp[b].arr[d]++;
        }else if(c==2){
            ans=0;
            for(int y=0;y<15;y++){
                ans=max(ans,mp[b].arr[y]);
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}