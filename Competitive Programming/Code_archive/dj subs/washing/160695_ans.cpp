// ans.cpp 9 Nov 16, 17:11:02 100 0 Judging completed in 7.73s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,f="CLEAN";
    int b,c,e;
    cin>>b>>c;
    e=b;
    for(int d=0;d<c;d=d+1){
        cin>>a;
        if(a=="USE"){
            if(e==0) f="DIRTY";
            e=e-1;
        }else if(a=="WASH") e=b;
    }
    cout<<f;
    return 0;
}