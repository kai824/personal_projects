// ans.cpp 18 Feb 17, 23:29:58 100 0 Judging completed in 4.875s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    string b;
    cin>>a>>b;
    for(int x=0;x<a;x++){
        for(int y=0;y<x;y++){cout<<' ';}
        cout<<b<<endl;
    }
    return 0;
}