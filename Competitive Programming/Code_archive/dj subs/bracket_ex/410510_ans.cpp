// ans.cpp 12 Nov 18, 13:13:21 60 1 Judging completed in 3.614s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#pragma O3
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    string a,c="",d=" ";
    int b;
    cin>>b>>a;
    map<char,char> brackets;
    brackets['(']=')';
    brackets['[']=']';
    brackets['{']='}';
    for(int x=0;x<b;x++){
        if(a[x]=='(' || a[x]=='[' || a[x]=='{'){
            d[0]=a[x];
            c=c+d;
        }else{
            if(c.length()==0){
                cout<<"Invalid";
                return 0;
            }
            if(a[x]==brackets[c[c.length()-1]]){
                c.erase(c.length()-1,1);
            }else{
                cout<<"Invalid";
                return 0;
            }
        }
    }
    if(c.length()==0){
        cout<<"Valid";
    }else{
        cout<<"Invalid";
    }
    return 0;
}