// ans.cpp 15 Jan 17, 14:17:53 100 0 Judging completed in 5.143s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int process(int a,int b){
    int d=a%b;
    a=b;
    b=d;
    if (b==0) return a;
    else return process(a,b);
}
int main() {
    int a,b,c;
    cin>>a>>b;
    if(b>a){
        c=a;
        a=b;
        b=c;
    }
    c=process(a,b);
    cout<<c;
    return 0;
}