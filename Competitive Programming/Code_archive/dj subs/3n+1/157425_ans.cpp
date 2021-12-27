// ans.cpp 31 Oct 16, 16:27:12 100 0 Judging completed in 3.927s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
void process(int a){
    cout<<a<<" ";
    if (a%2==0) a=a/2;
    else a=(3*a)+1;
    if (a!=1) process(a);
    else cout<<1;
}
int main() {
    int a;
    cin>>a;
    process(a);
    return 0;
}

