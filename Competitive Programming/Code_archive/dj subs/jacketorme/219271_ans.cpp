// ans.cpp 21 Aug 17, 21:26:36 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int b,c;
int main() {
    string a;
    cin>>a;
    size_t pos=a.find("JACKET", 0);
    while(pos!=string::npos){
        b++;
        pos=a.find("JACKET",pos+1);
    }
    pos=b.find("RANALD", 0);
    while(pos!=string::npos){
        c++;
        pos=a.find("RANALD",pos+1);
    }
    if(b>c)cout<<"JACKET";
    else cout<<"RANALD";
    return 0;
}