// ans.cpp 1 Feb 17, 19:04:59 0 0.22 Judging completed in 5.838s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin>>a;
    string b[a];
    for(int x=0;x<a;x++){
        cin>>b[x];
    }sort(b,b+a);
    for(int x=0;x<a;x++){
        cout<<b[x];
        if(x+1<a)cout<<' ';
    }
    return 0;
}