// ans.cpp 7 Feb 17, 13:09:31 100 0 Judging completed in 6.952s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin>>a;
    if (a>=80) cout<<"4.0";
    else if(a>=70) cout<<"3.6";
    else if(a>=65) cout<<"3.2";
    else if(a>=60) cout<<"2.8";
    else if(a>=55) cout<<"2.4";
    else if(a>=50) cout<<"2.0";
    else if(a>=45) cout<<"1.6";
    else if(a>=40) cout<<"1.2";
    else cout<<"0.8";
    return 0;
}