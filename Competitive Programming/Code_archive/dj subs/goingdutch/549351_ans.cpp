// ans.cpp 14 Aug 19, 22:25:15 0 0 Judging completed in 4.189s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[25];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,a,b,c,ans=0;
    cin>>n>>m;
    for(int x=0;x<n;x++){
        cin>>a>>b>>c;
        arr[a]+=c;arr[b]-=c;
    }
    set<int> ss;
    for(int x=0;x<n;x++){
        if(arr[x]!=0)ss.insert(arr[x]);
    }
    while(!ss.empty()){
        auto it=ss.begin(),it2=ss.end();
        it2--;
        a=*it2;//value
        a-=*it;
        ans++;//1 transaction
        ss.erase(it2);
        if(a!=0)ss.insert(a);
        ss.erase(it);
    }
    cout<<ans;
    return 0;
}