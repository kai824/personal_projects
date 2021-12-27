// ans.cpp 22 Jan 17, 17:55:07 100 0 Judging completed in 3.845s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin>>a;
    for(int x=1;x<=a;x++){
        cout<<x*x;
        if(x!=a)cout<<' ';
    }
    return 0;
}