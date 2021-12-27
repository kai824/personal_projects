// ans.cpp 14 Jun 18, 13:18:02 20 0 Judging completed in 4.569s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    if((n%2)==0){
        cout<<"-1\n";
    }else{
        for(int x=1;x<=n*n;x++){
            cout<<x;
            if((x%n)==0){
                cout<<'\n';
            }else cout<<' ';
        }
    }
    return 0;
}