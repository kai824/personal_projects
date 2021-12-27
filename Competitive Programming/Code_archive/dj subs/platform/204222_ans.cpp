// ans.cpp 15 Apr 17, 20:49:42 100 0 Judging completed in 4.613s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,t=0;
    cin>>n;
    for(int x=n-1;x>=0;x--){
        for(int y=0;y<x;y++){
            cout<<' ';
        }
        cout<<'/';
        for(int y=0;y<t;y++){
            cout<<' ';
        }
        cout<<'\\';
        t+=2;
        cout<<'\n';
    }
    t-=2;
    for(int x=0;x<n;x++){
        for(int y=0;y<x;y++){
            cout<<' ';
        }
        cout<<'\\';
        for(int y=0;y<t;y++){
            cout<<' ';
        }
        cout<<'/';
        t-=2;
        cout<<'\n';
    }
    return 0;
}