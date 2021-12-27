// ans.cpp 8 Aug 17, 18:06:06 66 1 Judging completed in 5.963s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
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
                break;
            }
        }
        if(!broke)break;
    }
    if(rar)cout<<"Rar";
    else cout<<"Weiliang";
    return 0;
}