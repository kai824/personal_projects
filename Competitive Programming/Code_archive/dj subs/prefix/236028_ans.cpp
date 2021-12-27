// ans.cpp 29 Oct 17, 12:38:17 100 0 Judging completed in 7.719s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m=100000,k;
    bool broke=false;
    cin>>n;
    string arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
        k=arr[x].length();
        m=min(m,k);
    }
    for(int x=0;x<m;x++){
        for(int y=1;y<n;y++){
            if(arr[y][x]!=arr[y-1][x]){
                broke=true;
                break;
            }
        }
        if(broke)break;
        cout<<arr[0][x];
    }
    return 0;
}