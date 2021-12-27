// ans.cpp 11 Jan 17, 16:09:32 100 0 Judging completed in 4.091s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin>>a;
    for(int x=1;x<=a;x++){
        cout<<(x*x);
        if(x<a)cout<<' ';
    }
    return 0;
}