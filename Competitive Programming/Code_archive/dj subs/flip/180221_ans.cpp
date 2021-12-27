// ans.cpp 12 Jan 17, 22:19:17 100 0.42 Judging completed in 6.988s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin>>a;
    long long int b[a],sum=0;
    for(int x=0;x<a;x++){
        cin>>b[x];
        sum+=b[x];
    }
    sum=sum/(a-1);
    for(int x=0;x<a;x++){
        cout<<sum-b[x]<<'\n';
    }
    return 0;
}