// ans.cpp 7 Feb 17, 13:15:38 100 0 Judging completed in 7.838s on AWS Oregon.
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