// ans.cpp 15 Apr 17, 20:13:11 60 0 Judging completed in 2.899s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a;
    int b=0;
    cin>>a;
    if(isalpha(a[0])){
        for(int x=0;x<a.length();x++){
            a[x]=toupper(a[x]);
        }
        cout<<a;
    }else{
        for(int x=0;x<a.length();x++){
            b*=10;
            b+=(a[x]-'0');
        }
        cout<<b;
    }
    return 0;
}