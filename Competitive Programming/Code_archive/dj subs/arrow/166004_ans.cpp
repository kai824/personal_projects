// ans.cpp 28 Nov 16, 20:29:25 0 0.04 Judging completed in 2.526s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int h,w;
    cin>>w>>h;
    int a=h/2;
    a=a+1;
    for(int b=0;b<a;b++){
        for(int c=0;c<b;c++){
            cout<<" ";
        }
        for(int c=0;c<w;c++){
            cout<<'*';
        }
        cout<<endl;
    }
    a=h/2;
    for(int b=a-1;b>=0;b--){
        for(int c=0;c<b;c++){
            cout<<" ";
        }
        for(int c=0;c<w;c++){
            cout<<'*';
        }
        cout<<endl;
    }
    return 0;
}