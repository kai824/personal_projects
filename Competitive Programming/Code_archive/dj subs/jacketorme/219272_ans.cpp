// ans.cpp 21 Aug 17, 21:27:13 100 0.33 Judging completed in 4.697s on AWS Oregon.
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
    pos=a.find("RANALD", 0);
    while(pos!=string::npos){
        c++;
        pos=a.find("RANALD",pos+1);
    }
    if(b>c)cout<<"JACKET";
    else cout<<"RANALD";
    return 0;
}