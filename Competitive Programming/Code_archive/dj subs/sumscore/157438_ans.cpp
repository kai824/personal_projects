// ans.cpp 31 Oct 16, 16:38:01 100 0 Judging completed in 4.229s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int process(){
    int a;
    cin>>a;
    if (a!=-1) return (a+process());
    else return 0;
}
int main() {
    int a=process();
    cout<<a;
    return 0;
}