// ans.cpp 5 Nov 16, 10:54:22 100 0 Judging completed in 3.923s on AWS Ireland.
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