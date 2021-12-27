// ans.cpp 21 Oct 17, 10:41:19 0 0 Judging completed in 6.745s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r,g,b;
    cin>>r>>b>>g;
    if((g+b-r)%2!=0){
        cout<<"Impossible";
        return 0;
    }
    cout<<(r+b-g)/2<<' '<<(r+g-b)/2<<' '<<(b+g-r)/2;
    return 0;
}