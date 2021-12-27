// ans.cpp 1 Feb 17, 19:00:35 100 0.06 Judging completed in 4.582s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    int a;
    cin>>a;
    for(int x=0;x<2*a-1;x++){
        for(int y=0;y<2*a-1;y++){
            cout<<min(min(x+1,2*a-1-x),min(y+1,2*a-1-y));
            if(y+1<2*a-1)cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}