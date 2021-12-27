// ans.cpp 18 May 19, 19:17:45 100 0.26 Judging completed in 3.337s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    uint64_t a,b;
    cin>>a;
    for(int x=0;x<a;x++){
        cin>>b;
        cout<<pow(b,1.0/3.0)<<endl;
    }
    return 0;
}