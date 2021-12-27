// ans.cpp 23 Apr 17, 16:17:58 50 0.3 Judging completed in 5.027s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
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