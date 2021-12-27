// ans.cpp 12 Nov 18, 21:52:26 100 0 Judging completed in 2.354s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,b="";
    getline(cin,a);
    for(int x=0;x<a.length();){
        if(!isalpha(a[x])){
            a.erase(x,1);
        }else if(isupper(a[x])){
            b=b+a[x];
            a.erase(x,1);
        }else{
            x++;
        }
    }cout<<b<<a;
    return 0;
}