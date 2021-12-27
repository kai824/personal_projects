// ans.cpp 17 Jan 18, 08:37:17 6 0.04 Judging completed in 11.487s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int cnt[10];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a,b;
    cin>>a>>a>>a>>b;
    for(int x=0;x<a.length();x++){
        for(int y=0;y<b.length();y++){
            if(a[x]==b[y]){
                if(y==0){
                    cnt[y]++;
                }else{
                    cnt[y]+=cnt[y-1];
                }
            }
        }
    }
    cout<<cnt[b.length()-1];
    return 0;
}