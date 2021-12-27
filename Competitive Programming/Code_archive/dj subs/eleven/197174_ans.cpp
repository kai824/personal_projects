// ans.cpp 6 Mar 17, 11:05:36 100 0.04 Judging completed in 3.897s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int c=0,b=0;
    string a;
    cin>>a;
    for(int x=0;x<a.length();x++){
        if(x%2==0){
            c+=(a[x]-'0');
        }else{
            b+=(a[x]-'0');
        }
    }if(abs(c-b)%11==0)cout<<"YES";
    else cout<<"NO";
    return 0;
}