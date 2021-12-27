// ans.cpp 12 Nov 18, 13:12:02 40 1 Judging completed in 3.901s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
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
            if(c.length()==0){\
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