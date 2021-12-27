// ans.cpp 7 Jan 20, 22:20:18 100 0 Judging completed in 4.054s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;int a=0;
    cin>>s;
    for(int x=0;x<s.length();x++){
        if(s[x]=='+')a++;else a--;
    }
    cout<<a;
    return 0;
}