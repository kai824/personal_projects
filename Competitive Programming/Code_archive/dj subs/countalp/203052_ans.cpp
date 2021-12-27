// ans.cpp 2 Apr 17, 16:31:29 100 0 Judging completed in 5.096s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int a,n[26];
int main() {
    cin>>a;
    string b;
    cin>>b;
    for(int x=0;x<b.length();x++){
        n[(int)b[x]-97]++;
    }
    for(int x=0;x<26;x++){
        cout<<(char)(x+97) <<' '<<n[x]<<'\n';
    }
    return 0;
}