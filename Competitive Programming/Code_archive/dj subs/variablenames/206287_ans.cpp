// ans.cpp 8 May 17, 18:00:42 100 0 Judging completed in 5.325s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    int c;
    cin>>c;
    for(int x=0;x<c;x++){
        cin>>a;
        b=" ";
        b[0]=a[0];
        for(int x=2;x<a.length();x++){
            if(a[x-1]=='_'){
                b=b+" ";
                b[b.length()-1]=a[x];
            }
        }
        if(b.length()>5)cout<<"CENSORED\n";
        else cout<<b<<'\n';
    }
    return 0;
}