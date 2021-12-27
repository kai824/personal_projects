// ans.cpp 6 Mar 17, 10:58:18 0 0 Judging completed in 6.855s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a;
    cin>>a;
    for(int x=1;x<=a.length();x++){
        for(int y=0;y<x;y++){
            cout<<' ';
        }
        cout<<a[a.length()-x];
        for(int y=0;y<(a.length()-2);y++){cout<<' ';}
        cout<<a[x-1];
        cout<<"\n";
    }
    for(int x=0;x<=a.length();x++){cout<<' ';}
    for(int x=1;x<=a.length();x++){
    	cout<<a[a.length()-x];
    }
    return 0;
}