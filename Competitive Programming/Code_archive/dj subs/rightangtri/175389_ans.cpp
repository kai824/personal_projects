// ans.cpp 28 Dec 16, 12:38:29 100 0 Judging completed in 3.521s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int x=1;x<=n;x++){
        for(int y=0;y<x;y++){
            cout<<'*';
        }
        cout<<endl;
    }
    return 0;
}