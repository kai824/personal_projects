// ans.cpp 23 Apr 17, 16:19:36 50 0.38 Judging completed in 7.697s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a[4];
    for(int x=0;x<4;x++){
        cin>>a[x];
    }
    for(int x=0;x<4;x++){
        for(int y=2;y<a[x];y++){
            if(a[x]%y==0){
                cout<<"Wrong code";
                return 0;
            }
        }
        if(a[x]==1){
            cout<<"Wrong code";
            return 0;
        }
    }
    cout<<"Opening...";
    return 0;
}