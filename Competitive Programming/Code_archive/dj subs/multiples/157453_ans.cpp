// ans.cpp 31 Oct 16, 17:14:05 100 0 Judging completed in 4.273s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
void process(int a,int b,int c){
    cout<<(a*c)<<endl;
    c++;
    if (b>c) process(a,b,c);
    else if (b==c) cout<<(a*c);
}
int main() {
    int a,b;
    cin>>a>>b;
    if (b>=1) process(a,b,1);
    return 0;
}