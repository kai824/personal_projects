// ans.cpp 22 Dec 16, 21:50:41 70 0.15 Judging completed in 8.119s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,ans=-INT_MAX,current=0;
    string beans;
    cin>>n;
    cin>>beans;
    for(int x=0;x<n;x++){
        if(beans[x]=='M'){
            if(current-2>0){
                current=current-2;
            }else{
                current=0;
            }
        }else{
            current+=(beans[x]-'0');
            ans=max(current,ans);
        }
    }
    if(ans==-INT_MAX)cout<<"-2\n";
    else cout<<ans<<endl;
    return 0;
}