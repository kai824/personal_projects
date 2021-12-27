// ans.cpp 28 Dec 16, 12:43:36 100 0 Judging completed in 4.943s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    if(n>=91)cout<<"A*";
    else if(n>=75)cout<<"A";
    else if(n>=60)cout<<"B";
    else if(n>=50)cout<<"C";
    else if(n>=35)cout<<"D";
    else if(n>=20)cout<<"E";
    else{
        cout<<"U";
    }
    return 0;
}