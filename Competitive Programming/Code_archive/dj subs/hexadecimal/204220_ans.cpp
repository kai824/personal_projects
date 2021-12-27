// ans.cpp 15 Apr 17, 20:39:13 100 0 Judging completed in 4.839s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,t;
    string a;
    bool b;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        b=false;
        for(int y=1;y<a.length();y++){
            t=(int)a[y];
            if(!((64<t && t<71)||(47<t && t<58))){
                b=true;
                break;
            }
        }
        if(b)cout<<"Not Hexadecimal\n";
        else cout<<"Hexadecimal\n";
    }
    return 0;
}