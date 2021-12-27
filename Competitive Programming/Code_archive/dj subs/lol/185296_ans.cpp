// ans.cpp 27 Jan 17, 21:44:06 25 1 Judging completed in 7.258s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a;
    uint64_t ans;
    cin>>ans>>a;
    ans=0;
    for(int x=0;x<a.length()-2;x++){
        if(a[x]=='L'){
            for(int y=x+1;y<a.length()-1;y++){
                if(a[y]=='O'){
                    for(int z=y+1;z<a.length();z++){
                        if(a[z]=='L'){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}