// ans.cpp 17 Jan 18, 08:38:44 0 0 Compilation failed on AWS Oregon.
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
                cnt[y]%=1e9+7;
            }
        }
    }
    cout<<cnt[b.length()-1];
    return 0;
}