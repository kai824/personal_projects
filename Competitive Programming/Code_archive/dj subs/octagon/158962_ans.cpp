// ans.cpp 5 Nov 16, 10:05:57 0 0 Compilation failed on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int process(a,b){
    int b=b+b-1+b-1;
    if (c>b/2) c=b-c-1;
    return a+2*c;
}
int main() {
    int a,b,d;
    cin>>a;
    b=a+a-1+a-1;
    for(int c=0;c<b;c=c+1){
        d=process(c,a);
        for(int e=0;e<(a+((a-1)*4));e=e+1){
            cout<<" ";
        }
        for(int e=0;e<b;e=e+1){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}