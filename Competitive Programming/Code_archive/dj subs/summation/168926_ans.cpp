// ans.cpp 10 Dec 16, 15:51:41 100 0.03 Judging completed in 5.346s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c=0;
    cin>>a;
    for(int x=0;x<a;x++){
        cin>>b;
        c+=abs(b);
    }
    cout<<c;
    return 0;
}