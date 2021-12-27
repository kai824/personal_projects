// ans.cpp 22 Mar 17, 19:20:28 0 2 Judging completed in 17.875s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a,b;
    int tc;
    cin>>tc;
    for(int x=0;x<tc;x++){
        cin>>a>>b;
        cout<<(long long) floor((double)b * log10((double)a))<<'\n';
    }
    return 0;
}