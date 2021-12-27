// ans.cpp 5 Nov 17, 21:41:30 0 0 Judging completed in 6.22s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,a,largests[3];
bool t(){
    int a,b,c;
    a=largests[0];
    b=largests[1];
    c=largests[2];
    if (a+b<=c) return 0;
    if (a+c<=b) return 0;
    if (b+c<=a) return 0;
    return 1;
}
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
        if(t()){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}