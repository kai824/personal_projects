// ans.cpp 3 Jun 18, 16:31:26 36 0.95 Judging completed in 4.459s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[2][15];
bool bit=1;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,a,ans=0;
    cin>>n>>k;
    cin>>a;
    a%=k;
    arr[0][a]=1;
    if(a==0)ans+=1;
    for(int x=1;x<n;x++){
        cin>>a;
        a%=k;
        for(int y=0;y<k;y++){arr[bit][y]=0;}
        arr[bit][a]=1;
        for(int y=0;y<k;y++){
            arr[bit][(y+a)%k]+=arr[!bit][y];
            if((y+a)%k==0)ans+=arr[bit][(y+a)%k];
        }
        bit=!bit;
    }
    cout<<ans;
    return 0;
}