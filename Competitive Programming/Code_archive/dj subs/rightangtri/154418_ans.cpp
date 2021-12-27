// ans.cpp 23 Oct 16, 20:15:41 100 0 Judging completed in 3.88s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c;
    cin>>a;
    for(b=0;b<a;b=b+1){
        for(c=a-b;c<=a;c=c+1){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}