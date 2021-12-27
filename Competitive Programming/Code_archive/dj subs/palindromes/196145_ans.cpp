// ans.cpp 1 Mar 17, 20:59:05 100 0.03 Judging completed in 2.854s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a;
    cin>>a;
    transform(a.begin(),a.end(),a.begin(),::tolower);
    for(int x=0;x<a.length()/2;x++){
        if(a[x]!=a[a.length()-1-x]){
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
    return 0;
}