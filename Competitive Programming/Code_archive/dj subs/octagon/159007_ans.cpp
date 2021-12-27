// ans.cpp 5 Nov 16, 10:17:09 0 0 Judging completed in 5.273s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int process(int c,int a){
    int b=a+a-1+a-1;
    if(c>b/2) c=b-c-1;
    return a+(2*(c+2));
}
int main() {
    int a,b,d;
    cin>>a;
    b=a+a-1+a-1;
    for(int c=0;c<b;c=c+1){
        d=process(c,a);
        for(int e=0;e<((a+((a-1)*4)-d));e=e+1){
            cout<<" ";
        }
        for(int e=0;e<d;e=e+1){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}