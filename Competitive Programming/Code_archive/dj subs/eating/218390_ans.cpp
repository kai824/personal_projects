// ans.cpp 8 Aug 17, 18:07:14 66 1 Judging completed in 27.612s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    bool rar=false,broke;
    cin>>a;
    cin>>a;
    while(true){
        broke=false;
        for(int x=1;x<a.length()-1;x++){
            if(a[x-1]!=a[x+1]){
                a.erase(x,1);
                rar=!rar;
                broke=true;
            }
        }
        if(!broke)break;
    }
    if(rar)cout<<"Rar";
    else cout<<"Weiliang";
    return 0;
}