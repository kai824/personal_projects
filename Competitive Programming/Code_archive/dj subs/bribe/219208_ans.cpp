// ans.cpp 20 Aug 17, 21:41:54 100 0.16 Judging completed in 5.309s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,e,a,b;
    cin>>n;
    int costs[n],friends[n];
    for(int x=0;x<n;x++)cin>>costs[x];
    cin>>e;
    for(int x=0;x<e;x++){
        cin>>a>>b;
        a--;
        b--;
        friends[a]++;
        friends[b]++;
    }
    a=0;//now used as ans...
    for(int x=1;x<n;x++){
        if((double)friends[x]/costs[x]>(double)friends[a]/costs[a]){
            a=x;
        }
    }
    cout<<a+1;
    return 0;
}