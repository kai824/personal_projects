// ans.cpp 13 Feb 17, 09:52:43 60 0 Judging completed in 3.152s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a;
    bool b=false;
    int ans=0;
    getline(cin,a);
    for(int x=0;x<a.length();x++){
        if(isalpha(a[x]))b=true;
        else{
            if(b){
                b=false;
                ans++;
            }
        }
    }
    if(b)ans++;
    cout<<ans;
    return 0;
}