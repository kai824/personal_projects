// ans.cpp 9 Jan 17, 09:30:35 100 0 Judging completed in 4.765s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin>>a;
    for(int x=1;x<=a;x++){
        for(int y=0;y<x;y++){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}