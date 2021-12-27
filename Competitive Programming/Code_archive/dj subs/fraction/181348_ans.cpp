// ans.cpp 15 Jan 17, 14:21:09 37 0 Judging completed in 6.383s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int process(int a,int b){
    if(b>a)swap(a,b);
    if(b==0)return a;
    else return process(b,a%b);
}
int main() {
    int a,b,c;
    cin>>a>>b;
    c=process(a,b);
    cout<<a/c<<'/'<<b/c;
    return 0;
}