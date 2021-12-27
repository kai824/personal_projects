// ans.cpp 5 Nov 17, 21:36:32 0 0 Judging completed in 4.447s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,a,largests[3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        if(a>largests[2]){
            largests[0]=largests[1];
            largests[1]=largests[2];
            largests[2]=a;
        }else if(a>largests[1]){
            largests[0]=largests[1];
            largests[1]=a;
        }else if(a>largests[0]){
            largests[0]=a;
        }
        if(largests[0]+largests[1]>largests[2]){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}