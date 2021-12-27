// ans.cpp 18 Feb 17, 23:40:35 100 0 Judging completed in 2.556s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin>>a;
    for(int x=0;(true);x++){
        if(a==x*x){
            cout<<"yes";
            break;
        }else if(a<x*x){
            cout<<"no";
            break;
        }
    }
    return 0;
}