// ans.cpp 20 Aug 17, 17:01:43 0 0.93 Judging completed in 7.423s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
struct ds{
    int arr[10]={0,0,0,0,0,0,0,0,0,0};
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    map<string, ds> mp;
    int a,ans;
    string b;
    short int c,d;
    cin>>a;
    for(int x=0;x<a;x++){
        cin>>b>>c;
        if(c==1){
            cin>>d;
            mp[b].arr[d]++;
        }else{
            ans=0;
            for(int y=0;y<10;y++){
                ans=max(ans,mp[b].arr[y]);
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}