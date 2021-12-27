// ans.cpp 17 Jan 18, 08:41:31 100 0.07 Judging completed in 6.544s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int cnt[10][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a,b;
    cin>>a>>a>>a>>b;
    for(int x=0;x<a.length();x++){
        for(int y=0;y<b.length();y++){
            cnt[y][x%2]=cnt[y][!(x%2)];
            if(a[x]==b[y]){
                if(y==0){
                    cnt[y][x%2]++;
                }else{
                    cnt[y][x%2]+=cnt[y-1][!(x%2)];
                }
                cnt[y][x%2]%=1000000007;
            }
        }
    }
    cout<<cnt[b.length()-1][(a.length()-1)%2];
    return 0;
}