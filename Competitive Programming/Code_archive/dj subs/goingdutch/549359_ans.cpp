// ans.cpp 14 Aug 19, 22:35:14 0 0 Judging completed in 3.516s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[25];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,a,b,c,ans=0;
    cin>>m>>n;
    for(int x=0;x<n;x++){
        cin>>a>>b>>c;
        arr[a]+=c;arr[b]-=c;
    }
    multiset<int> ss;
    for(int x=0;x<m;x++){
        if(arr[x]!=0)ss.insert(arr[x]);
    }
    while(!ss.empty()){
        auto it=ss.begin(),it2=ss.end();
        if(*it==0){
            ss.erase(it);
        }
        it2--;
        a=*it2;//value
        a+=*it;
        ans++;//1 transaction
        ss.erase(it2);
        ss.erase(it);
        if(a!=0)ss.insert(a);
    }
    cout<<ans;
    return 0;
}