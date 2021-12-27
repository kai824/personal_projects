// ans.cpp 1 May 17, 20:16:32 80 0 Judging completed in 6.569s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a[4],root;
    for(int x=0;x<4;x++){
        cin>>a[x];
    }
    for(int x=0;x<4;x++){
        if(a[x]<=1){
            cout<<"Wrong code\n";
            return 0;
        }
        root=sqrt(a[x]);
        for(int y=2;y<root;y++){
            if(a[x]%y==0){
                cout<<"Wrong code\n";
                return 0;
            }
        }
    }
    cout<<"Opening...\n";
    return 0;
}