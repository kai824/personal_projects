// ans.cpp 29 Apr 17, 19:31:57 0 0.98 Judging completed in 5.643s on AWS Oregon.
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
    }
    if(largests[0]+largests[1]>largests[2])cout<<"YES";
    else cout<<"NO";
    return 0;
}