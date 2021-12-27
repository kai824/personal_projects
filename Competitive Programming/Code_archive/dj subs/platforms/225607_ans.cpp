// ans.cpp 21 Oct 17, 11:26:36 26 0.13 Judging completed in 7.378s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,cur=2;
    cin>>n>>k;
    if(k==1){
        cout<<"1\n";
        for(int x=1;x<=n;x++){
            cout<<x;
            if(x<n)cout<<' ';
        }
    }if(k==2){
        cout<<(n-(n%2)-1)<<" 2\n";
        for(int x=0;x<n;x++){
            cout<<cur;
            if(x+1<n)cout<<' ';
            cur+=2;
            if(cur>n)cur=1;
        }
    }
    return 0;
}