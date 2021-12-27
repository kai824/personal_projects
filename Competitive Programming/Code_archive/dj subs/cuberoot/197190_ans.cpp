// ans.cpp 6 Mar 17, 12:35:43 100 0.39 Judging completed in 7.113s on AWS Oregon.
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