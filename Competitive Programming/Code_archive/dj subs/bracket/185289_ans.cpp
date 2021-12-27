// ans.cpp 27 Jan 17, 21:02:16 100 0 Judging completed in 7.089s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a;
    int b;
    cin>>b>>a;
    b=0;
    for(int x=0;x<a.length();x++){
        if(a[x]=='(')b++;
        else b--;
        if(b<0){
            cout<<"Invalid";
            return 0;
        }
    }if(b==0){
        cout<<"Valid";
    }else{
        cout<<"Invalid";
    }
    return 0;
}