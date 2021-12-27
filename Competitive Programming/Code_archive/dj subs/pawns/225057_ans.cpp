// ans.cpp 20 Oct 17, 20:27:52 100 0.2 Judging completed in 7.596s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int countx[1000005],n,ans[1000005],a,maxi,mm;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        countx[a]++;
        ans[x]=countx[a];
        maxi=max(maxi,a);
        mm=max(mm,ans[x]);
    }
    for(int x=1;x<maxi;x++){
        if(countx[x]<countx[x+1]){
            cout<<-1;
            return 0;
        }
    }
    cout<<mm<<'\n';
    for(int x=0;(x+1)<n;x++){
        cout<<ans[x]<<' ';
    }
    cout<<ans[n-1];
    return 0;
}