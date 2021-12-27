// ans.cpp 7 Feb 17, 13:30:07 0 0 Compilation failed on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string a,b="";(
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        if(a.length()>b.length())b=a;
    }
    cout<<b;
    return 0;
}