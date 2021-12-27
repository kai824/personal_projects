// ans.cpp 29 Mar 17, 21:06:07 100 0.03 Judging completed in 5.017s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,ans=-INT_MAX,current=0;
    string beans;
    cin>>n;
    cin>>beans;
    if (n==0){
        cout<<endl;
        return 0;
    }
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
    if(ans==-INT_MAX)cout<<"0\n";
    else cout<<ans<<endl;
    return 0;
}