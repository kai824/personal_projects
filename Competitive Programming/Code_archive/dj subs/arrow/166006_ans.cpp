// ans.cpp 28 Nov 16, 20:36:32 0 0.04 Judging completed in 2.582s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int h,w,w2;
    cin>>h>>w2;
    w=h/2;
    w=w2-w;
    int a=h/2;
    a=a+1;
    for(int b=0;b<a;b++){
        for(int c=0;c<b;c++){
            cout<<" ";
        }
        for(int c=0;c<w;c++){
            cout<<'*';
        }
        for(int c=0;c<w2-b;c++){
            cout<<" ";
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
        for(int c=0;c<w2-b;c++){
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}