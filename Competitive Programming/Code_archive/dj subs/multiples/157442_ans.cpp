// ans.cpp 31 Oct 16, 16:45:45 80 1 Judging completed in 6.819s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
void process(int a,int b,int c){
    cout<<(a*c)<<endl;
    c=c+1;
    if (b!=c) process(a,b,c);
    else cout<<(a*c);
}
int main() {
    int a,b;
    cin>>a>>b;
    process(a,b,1);
    return 0;
}