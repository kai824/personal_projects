// ans.cpp 8 Mar 17, 13:27:44 100 0 Judging completed in 3.138s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int a[26],b[26];
string c,d;
int main() {
    getline(cin,c);
    for(int x=0;x<c.length();x++){
        if(!isalpha(c[x]))continue;
        c[x]=char(tolower(c[x]));
        a[int(c[x])-97]++;
    }
    getline(cin,d);
    for(int x=0;x<d.length();x++){
        if(!isalpha(d[x]))continue;
        d[x]=char(tolower(d[x]));
        b[int(d[x])-97]++;
    }
    for(int x=0;x<26;x++){
        if(a[x]!=b[x]){
        	cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}