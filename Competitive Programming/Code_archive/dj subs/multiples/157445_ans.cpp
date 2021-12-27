// ans.cpp 31 Oct 16, 16:46:50 80 1 Judging completed in 5.214s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
void process(int a,int b,int c){
    cout<<(a*c)<<endl;
    c++;
    if (b!=c) process(a,b,c);
    else cout<<(a*c);
}
int main() {
    int a,b;
    cin>>a>>b;
    process(a,b,1);
    return 0;
}