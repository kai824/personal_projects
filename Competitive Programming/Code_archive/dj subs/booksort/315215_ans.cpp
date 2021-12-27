// ans.cpp 11 Jan 18, 09:15:17 100 0.03 Judging completed in 5.738s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int it[300005];//it[a] stores the iterator in the list to find book a...
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,a;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        it[a]=x;
    }
    for(int x=n-1;x>=0;x--){
        if(it[x]>=it[x+1]){
            //wrong ordering...
            cout<<x;return 0;
        }
    }
    cout<<"0";
    return 0;
}